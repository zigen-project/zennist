#pragma once

#include <bits/types/FILE.h>
#include <stdio.h>
#include <zukou.h>
//
#include <jpeglib.h>

#include "texture.h"

namespace zennist {

class JpegTexture final : public zukou::GlTexture, public Texture
{
 public:
  DISABLE_MOVE_AND_COPY(JpegTexture);
  JpegTexture(zukou::System *system);
  ~JpegTexture();

  bool Init();

  bool Load(const char *filename);

 private:
  bool loaded_ = false;

  int fd_ = 0;
  zukou::ShmPool pool_;
  zukou::Buffer texture_buffer_;
};

}  // namespace zennist
