#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

/**
   Processes a pixel by forming the negative.
   @param blue the blue value of the pixel
   @param green the green value of the pixel
   @param red the red value of the pixel
*/
void process(int& blue, int& green, int& red)
{
   blue = 255 - blue;
   green = 255 - green;
   red = 255 - red;
}

/**
   Gets an integer from a binary stream.
   @param stream the stream
   @param offset the offset at which to read the integer
   @return the integer starting at the given offset
*/
int get_int(fstream& stream, int offset)
{
   stream.seekg(offset);
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;
   // Open as a binary file
   stream.open(filename, ios::in | ios::out | ios::binary);
   
   int file_size = get_int(stream, 2); // Get the image dimensions
   int start = get_int(stream, 10);
   int width = get_int(stream, 18);
   int height = get_int(stream, 22);

   // Scan lines must occupy multiples of four bytes
   int scanline_size = width * 3;
   int padding = 0;
   if (scanline_size % 4 != 0)
   {
      padding = 4 - scanline_size % 4;
   }

   if (file_size != start + (scanline_size + padding) * height)
   {
      cout << "Not a 24-bit true color image file." << endl;
      return 1;
   }
   
   int pos = start;

   for (int i = 0; i < height; i++) // For each scan line
   {
      for (int j = 0; j < width; j++) // For each pixel
      {
         stream.seekg(pos); // Go to the next pixel
         int blue = stream.get(); // Read the pixel
         int green = stream.get();
         int red = stream.get();

         process(blue, green, red); // Process the pixel

         stream.seekp(pos); // Go back to the start of the pixel

         stream.put(blue); // Write the pixel
         stream.put(green);
         stream.put(red);
         pos = pos + 3;
      }

      stream.seekg(padding, ios::cur); // Skip the padding
      pos = pos + padding;
   }

   return 0;
}
