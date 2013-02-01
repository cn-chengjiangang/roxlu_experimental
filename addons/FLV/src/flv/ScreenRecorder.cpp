#include <flv/ScreenRecorder.h>

// @todo we probably want a bigger distance between the read and write 
// PBO indices.

ScreenRecorder::ScreenRecorder() 
  :width(0)
  ,height(0)
  ,channels(4)
  ,pixels(NULL)
  ,dx(0)
  ,is_recording(false)
  ,is_file_opened(false)
{
  memset(pbos, 0, sizeof(pbos));
}

ScreenRecorder::~ScreenRecorder() {
#if !defined(SCREEN_RECORDER_USE_PBO) 
  if(pixels != NULL) {
    delete[] pixels;
    pixels = NULL;
  }
#endif
  is_file_opened = false;
  is_recording = false;
  width = 0;
  channels = 0;
  dx = 0;
}

bool ScreenRecorder::open(std::string filepath) {
  RX_VERBOSE(("Open file: %s", filepath.c_str()));

  if(!flv_writer.open(filepath)) {
    return false;
  }
  is_file_opened = true;
  return true;
}

bool ScreenRecorder::setup(unsigned int inw, 
                           unsigned int inh,
                           unsigned int outw,
                           unsigned int outh,
                           int fps)
{

  av.setVerticalFlip(true);

  if(!av.setupVideo(inw, inh, outw, outh, fps, AV_FMT_BGRA32, &flv)) {
    return false;
  }

  flv.setCallbacks(&FLVFileWriter::write,
                   &FLVFileWriter::rewrite,
                   &FLVFileWriter::flush,
                   &FLVFileWriter::close,
                   &flv_writer);



  this->width = inw;
  this->height = inh;

#if !defined(SCREEN_RECORDER_USE_PBO)
  pixels = new unsigned char[inw * inh * channels];
  memset(pixels, 0, inw * inh * channels);
#endif

  if(!av.initialize()) {
    RX_WARNING(("cannot initialize AV."));
    return false;
  }

#if defined(SCREEN_RECORDER_USE_PBO) 
  glGenBuffers(SCREEN_RECORDER_NUM_PBOS, pbos);
  for(int i = 0; i < SCREEN_RECORDER_NUM_PBOS; ++i) {
    glBindBuffer(GL_PIXEL_PACK_BUFFER, pbos[i]);
    glBufferData(GL_PIXEL_PACK_BUFFER, inw * inh * channels, pixels, GL_STREAM_READ);
  }

  glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
#endif

  return true;
}

void ScreenRecorder::grabFrame() {

  if(!is_recording) {
    RX_WARNING(("stopped, cant grab."));
    return;
  }

#if !defined(SCREEN_RECORDER_USE_PBO)
  if(av.wantsNewVideoFrame()) {
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    av.addVideoFrame(pixels);
  }
#else
  if(av.wantsNewVideoFrame()) {
    RX_VERBOSE(("Grab a frame."));
    rx_int64 now = rx_millis();
    int write_dx = (dx++) % SCREEN_RECORDER_NUM_PBOS;
    int read_dx = (write_dx + 1) % SCREEN_RECORDER_NUM_PBOS;

    glBindBuffer(GL_PIXEL_PACK_BUFFER, pbos[write_dx]);
    glReadPixels(0, 0, width, height, GL_BGRA, GL_UNSIGNED_BYTE, 0); 

    glBindBuffer(GL_PIXEL_PACK_BUFFER, pbos[read_dx]);
    GLubyte* ptr = (GLubyte*) glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
    if(ptr) {
      av.addVideoFrame(ptr);
      glUnmapBuffer(GL_PIXEL_PACK_BUFFER);

    }
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
  }

#endif
}

void ScreenRecorder::start() {
  if(is_recording) {
    RX_WARNING(("already started."));
    return;
  }

  RX_VERBOSE(("Start recording."));
  is_recording = true;
  av.start();
}

void ScreenRecorder::stop() {
  if(!is_recording) {
    RX_WARNING(("already stopped."));
    return;
  }

  RX_VERBOSE(("Stop recording."));
  av.stop();
  is_recording = false;
  is_file_opened = false; // av.stop() calls close on the flv writer
}
