#include <roxlu/opengl/Texture.h>
#include <roxlu/opengl/Error.h>
#include <roxlu/io/File.h>

#ifdef ROXLU_WITH_OPENGL

namespace roxlu {

  Texture::Texture() 
    :wrap_s(GL_CLAMP_TO_EDGE) // GL_CLAMP_TO_EDGE (gl es)
    ,wrap_t(GL_CLAMP_TO_EDGE)
    ,min_filter(GL_LINEAR)
    ,mag_filter(GL_LINEAR)
    ,internal_format(GL_RGBA)

  {
    glGenTextures(1, &texture_id); eglGetError();
  }

  Texture::~Texture() {
  }

  void Texture::setParams() {
    bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s); eglGetError(); // or GL_CLAMP (=> clamp give artifacts with uvsphere) ?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t); eglGetError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter); eglGetError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter); eglGetError();
    unbind();

  }

  void Texture::setPixels(const unsigned char* pixels, int width, int height, GLenum format) {
    bind();
    glTexImage2D(
		 GL_TEXTURE_2D
                 ,0
                 ,internal_format 
                 ,width
                 ,height
                 ,0
                 ,format
                 ,GL_UNSIGNED_BYTE
                 ,pixels
                 );
    setParams();
    eglGetError();
    unbind();
  }

  string Texture::getImageFilePath() {
    return File::toDataPath(image_file);
  }

  void Texture::bind() {
    glEnable(GL_TEXTURE_2D);	
    glBindTexture(GL_TEXTURE_2D, texture_id); 
  }

  void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D,0); 
  }

  GLuint Texture::getID() {
    return texture_id;
  }

}; // roxlu

#endif // ROXLU_WITH_OPENGL
