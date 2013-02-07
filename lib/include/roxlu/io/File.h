#ifndef ROXLU_FILEH
#define ROXLU_FILEH

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <roxlu/core/Log.h>
#include <roxlu/core/platform/Platform.h>
#include <sys/stat.h>


#if defined(_WIN32)
#   include <roxlu/external/dirent.h> 
#else
#   include <dirent.h>
#endif

#if ROXLU_PLATFORM == ROXLU_APPLE || ROXLU_PLATFORM == ROXLU_IOS
#  include <TargetConditionals.h>
#  include <mach-o/dyld.h>

#elif ROXLU_PLATFORM == ROXLU_WINDOWS
#  include <windows.h>
#  include <direct.h> // _mkdir

#elif ROXLU_PLATFORM == ROXLU_LINUX
#  include <unistd.h> // getcwd

#endif

using std::string;
using std::ofstream;

namespace roxlu {

	
  class File {
  public:
    File();
    ~File();
	
    static void putFileContents(string file, string contents, bool inDataPath = true) {
      ofstream of;
      if(inDataPath) {
        file = File::toDataPath(file);	
      }
		
      of.open(file.c_str(), std::ios::out);
      if(!of.is_open()) {
        RX_ERROR(("File: cannot open file: '%s'\n", file.c_str()));
        return;
      }
      of.write(contents.c_str(), contents.length());
      of.close();
    }
	
    static string getFileContents(string file, bool inDataPath = true) {
      if(inDataPath) {
        file = File::toDataPath(file);
      }
      std::string result = "";
      std::string line = "";
      std::ifstream ifs(file.c_str());
      if(!ifs.is_open()) {
        RX_ERROR(("File: cannot open file: '%s'\n", file.c_str()));
        return result;
      }
      while(getline(ifs,line)) {
        result += line +"\n";
      }
      return result;
    }
	
    static string toDataPath(string file) {
      return toDataPath(file.c_str());
    }	          
	
    static string toDataPath(const char* file) {
#if ROXLU_PLATFORM == ROXLU_APPLE
#if ROXLU_GL_WRAPPER == ROXLU_OPENFRAMEWORKS
      return getCWD() +"/../../../data/" +file;	
      // #elif ROXLU_GL_WRAPPER == ROXLU_GLFW
#else
      return getCWD() +"data/" +file;	
#endif
#elif ROXLU_PLATFORM == ROXLU_IOS
      return getCWD() +file;
#elif ROXLU_PLATFORM == ROXLU_WINDOWS
      return getCWD() +"\\data\\" +file;
#elif ROXLU_PLATFORM == ROXLU_LINUX
      return getCWD() +"/data/" +file;
#else	
      return getCWD() +"/" +file;
#endif
    }
	
    static time_t getTimeModified(string file, bool inDataPath = true) {
      if(inDataPath) {
        file = File::toDataPath(file);
      }
      printf("MUST IMPLEMENT getTimeModified\n");
      return 0;
    }
	
    static string getCWD() {
#if ROXLU_PLATFORM == ROXLU_APPLE  || ROXLU_PLATFORM == ROXLU_IOS
      // hackedyhack
      char path[1024];
      uint32_t size = sizeof(path);
      if (_NSGetExecutablePath(path, &size) != 0) {
        RX_WARNING(("buffer too small; need size %u", size));
      }
      char res[1024];
      char* clean = realpath(path, res);
      if(clean) {
        string fullpath(clean);
        size_t pos = fullpath.find_last_of('/');
        if(pos != std::string::npos) {
          string noexe = fullpath.substr(0,pos+1);
          return noexe;
        }
      }
      return clean;
#elif ROXLU_PLATFORM == ROXLU_WINDOWS
      char buffer[MAX_PATH];
      GetModuleFileNameA( NULL, buffer, MAX_PATH );
      string::size_type pos = string( buffer ).find_last_of( "\\/" );
      return string( buffer ).substr( 0, pos);
#else
      char buf[1024];
      getcwd(buf, 1024);		
      return buf;
#endif
    }

    // e.g.: File::createPath("/users/home/roxlu/data/images/2012/12/05/")
    static bool createPath(std::string path) {
      std::vector<std::string> dirs;
      while(path.length() > 0) {
        //        int index = path.find(RX_PATH_SEPARATOR);
        int index = path.find('/');
        std::string dir = (index == -1 ) ? path : path.substr(0, index);
        if(dir.length() > 0) {
          dirs.push_back(dir);
        }
        if(index + 1 >= path.length() || index == -1) {
          break;
        }
        path = path.substr(index + 1);
      }
    
      struct stat s;
      std::string dir_path;
      for(unsigned int i = 0; i < dirs.size(); i++) {
        //        dir_path.push_back(RX_PATH_SEPARATOR);
        dir_path.push_back('/');
        dir_path += dirs[i];
        if(stat(dir_path.c_str(), &s) != 0) {
          if(!File::createDirectory(dir_path.c_str())) {
            RX_ERROR(("Cannot create directory: %s", dir_path.c_str()));
            return false;
          }
        }
      }
      return true;
    }

    static bool createDirectory(std::string path) {
      printf("create dir: %s\n", path.c_str());
#ifdef _WIN32
	 
      if(_mkdir(path.c_str()) != 0) {
        if(errno == ENOENT) { 
          RX_ERROR(("Cannot create directory: %s (ENOENT)", path.c_str()));
          return false;
        }
        else if(errno == EEXIST) {
          RX_ERROR(("Cannot create directory: %s (EEXIST)", path.c_str()));
        }
      }
      return true;
#else
      if(mkdir(path.c_str(), 0777) != 0) {
        RX_ERROR(("Cannot create directory: %s", path.c_str());
          return false;
          }
          return true;
#endif
      }
    
      static std::vector<std::string> getDirectories(std::string path) {
        std::vector<std::string> result;
        DIR* dir;
        struct dirent* ent;
        if((dir = opendir(path.c_str())) != NULL) {
          while((ent = readdir(dir)) != NULL) {
            if(ent->d_type == DT_DIR) {
              if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
              }
              result.push_back(ent->d_name);
            }
          }
          closedir(dir);
        }
        return result;
      }
    
      static std::vector<std::string> getFiles(std::string path) {
        std::vector<std::string> result;
        DIR* dir;
        struct dirent* ent;
        if((dir = opendir(path.c_str())) != NULL) {
          while((ent = readdir(dir)) != NULL) {
            if(ent->d_type == DT_REG) {
              result.push_back(path +"/" +ent->d_name);
            }
          }
          closedir(dir);
        }
        return result;
      }



    }; // File
  } // roxlu

#endif
