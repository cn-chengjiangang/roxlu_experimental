# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Applications/CMake 2.8-3.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-3.app/Contents/bin/cmake" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-3.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build

# Include any dependencies generated for this target.
include tests/curl_download/CMakeFiles/curl_download.dir/depend.make

# Include the progress variables for this target.
include tests/curl_download/CMakeFiles/curl_download.dir/progress.make

# Include the compile flags for this target's objects.
include tests/curl_download/CMakeFiles/curl_download.dir/flags.make

tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o: tests/curl_download/CMakeFiles/curl_download.dir/flags.make
tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o: ../curl_download/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/curl_download.dir/main.cpp.o -c /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/curl_download/main.cpp

tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curl_download.dir/main.cpp.i"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/curl_download/main.cpp > CMakeFiles/curl_download.dir/main.cpp.i

tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curl_download.dir/main.cpp.s"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/curl_download/main.cpp -o CMakeFiles/curl_download.dir/main.cpp.s

tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.requires:
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.requires

tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.provides: tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.requires
	$(MAKE) -f tests/curl_download/CMakeFiles/curl_download.dir/build.make tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.provides.build
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.provides

tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.provides.build: tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.provides.build

tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o: tests/curl_download/CMakeFiles/curl_download.dir/flags.make
tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o: ../../src/kurl/Kurl.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o -c /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/src/kurl/Kurl.cpp

tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.i"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/src/kurl/Kurl.cpp > CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.i

tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.s"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/src/kurl/Kurl.cpp -o CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.s

tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.requires:
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.requires

tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.provides: tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.requires
	$(MAKE) -f tests/curl_download/CMakeFiles/curl_download.dir/build.make tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.provides.build
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.provides

tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.provides.build: tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.provides.build

# Object files for target curl_download
curl_download_OBJECTS = \
"CMakeFiles/curl_download.dir/main.cpp.o" \
"CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o"

# External object files for target curl_download
curl_download_EXTERNAL_OBJECTS =

tests/curl_download/curl_download: tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o
tests/curl_download/curl_download: tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o
tests/curl_download/curl_download: ../../lib/mac/64/libcurl.a
tests/curl_download/curl_download: tests/curl_download/CMakeFiles/curl_download.dir/build.make
tests/curl_download/curl_download: tests/curl_download/CMakeFiles/curl_download.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable curl_download"
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/curl_download.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/curl_download/CMakeFiles/curl_download.dir/build: tests/curl_download/curl_download
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/build

tests/curl_download/CMakeFiles/curl_download.dir/requires: tests/curl_download/CMakeFiles/curl_download.dir/main.cpp.o.requires
tests/curl_download/CMakeFiles/curl_download.dir/requires: tests/curl_download/CMakeFiles/curl_download.dir/__/__/src/kurl/Kurl.cpp.o.requires
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/requires

tests/curl_download/CMakeFiles/curl_download.dir/clean:
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download && $(CMAKE_COMMAND) -P CMakeFiles/curl_download.dir/cmake_clean.cmake
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/clean

tests/curl_download/CMakeFiles/curl_download.dir/depend:
	cd /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/curl_download /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download /Users/diederickhuijbers/of/addons_diederick/roxlu/addons/Curl/tests/build/tests/curl_download/CMakeFiles/curl_download.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/curl_download/CMakeFiles/curl_download.dir/depend

