#include <string>
#include <vector>
#include "picture.h"
#include "jo_gif.h"
#include "jo_mpeg.h"
#include <cstdio>


using namespace std;

class Animation
{
 public:
   Animation(string filename, int width, int height);
   void add(const Picture& pic, int x, int y);
   void frame();
   void close();
 private:
   jo_gif_t _gif;
   FILE* _fp;
   vector<unsigned char> _frame;
   int _width;
   int _height;   
};
