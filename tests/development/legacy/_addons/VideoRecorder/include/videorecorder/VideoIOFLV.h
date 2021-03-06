#ifndef ROXLU_VIDEORECORDER_VIDEOIOFLVH
#define ROXLU_VIDEORECORDER_VIDEOIOFLVH

#include <videorecorder/VideoIO.h>
#include <videorecorder/FLV.h>
#include <videorecorder/VideoTypes.h>
#include <roxlu/Roxlu.h>


class VideoIOFLV : public VideoIO {
 public:
  int getType();
  int writeOpenFile(VideoParams* p);
  int writeParams(VideoParams* p);
  int writeHeaders(VideoParams* p);
  int writeCloseFile(VideoParams* p);
  int writeVideoPacket(VideoPacket* p);
  int writeAudioPacket(AudioPacket* p);
  virtual void flush(Buffer& buffer); // for VideoIOFLVSocket
 private:
  FLV flv;
  std::string filepath;
};

#endif



