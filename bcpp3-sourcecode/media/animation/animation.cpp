#include "animation.h"
#include <algorithm>

Animation::Animation(string filename, int width, int height) : _frame(width * height * 4)
{
   _width = width;
   _height = height;
   fill(_frame.begin(), _frame.end(), 255); // fill with white
   if (filename.substr(filename.length() - 4) == ".gif")
   {
      _gif = jo_gif_start(filename.c_str(), width, height, 0, 32);
      _fp = NULL;
   }
   else
   {
      _fp = fopen(filename.c_str(), "wb");
   }
}

void Animation::add(const Picture& pic, int x, int y)
{
   for (int py = 0; py < pic._height; py++)
      for (int px = 0; px < pic._width; px++)
      {
         int fx = x + px;
         int fy = y + py;
         if (0 <= fx && fx < _width && 0 <= fy && fy < _height)
         {
            int foff = (fy * _width + fx) * 4;
            int poff = (py * pic._width + px) * 4;
            _frame[foff] = pic._values[poff];
            _frame[foff + 1] = pic._values[poff + 1];
            _frame[foff + 2] = pic._values[poff + 2];            
         }
      }
}

void Animation::frame()
{
   if (_fp == NULL)
   {
      jo_gif_frame(&_gif, _frame.data(), 4, true);
   }
   else
   {
      jo_write_mpeg(_fp, _frame.data(), _width, _height, 60);
   }
   fill(_frame.begin(), _frame.end(), 255); // fill with white
}

void Animation::close()
{
   if (_fp == NULL)
   {
      jo_gif_end(&_gif);
   }
   else
   {
      fclose(_fp);
   }
}
