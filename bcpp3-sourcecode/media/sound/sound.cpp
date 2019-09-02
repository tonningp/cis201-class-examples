#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*
   This program processes a 16 bit uncompressed mono .WAV file.
*/

/**
   Processes the sound samples. Modify this function to change
   the way the sound is processed.
   @param samples the sound samples in the sound file
   @param size the number of samples
   @param sample_rate the number of samples per second
*/
void process(int samples[], int size, int sample_rate)
{
   // Here, we make the sound three times as loud
   // In this example, we don't need the sample rate

   for (int i = 0; i < size; i++)
   {
      samples[i] = 3 * samples[i];
   }
}

// -------------------------------------------------------------------

/*
  The code below processes a file in the WAV format.
  You can use this program to manipulate sound files without 
  reading or understanding the code below. 

  The code uses C++ features that are introduced in chapters 7 and 8, 
  as well as the internals of the WAV format 
  (https://ccrma.stanford.edu/courses/422/projects/WaveFormat/)
*/

/**
   Gets an unsigned 4-byte integer from a binary stream.
   @param stream the stream
   @return the integer 
*/
int get_unsigned_int4(fstream& stream)
{
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}

/**
   Gets an unsigned 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_unsigned_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   return lo + 256 * hi;
}

/**
   Gets a signed 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_signed_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   int result = lo + 256 * hi;
   if (result >= 32768) { result = result - 65536; }
   return result;
}

/**
   Puts a signed 2-byte integer to a binary stream.
   @param stream the stream
   @param value the integer to put
*/
void put_signed_int2(fstream& stream, int value)
{
   if (value < 0) { value = value + 65536; }
   stream.put(value % 256);
   stream.put(value / 256);
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;

   // Open as a binary file
   stream.open(filename.c_str(), ios::in | ios::out | ios::binary);

   // Check that we can handle this file
   stream.seekg(20);
   int format_type = get_unsigned_int2(stream);
   if (format_type != 1)
   {
      cout << "Not an uncompressed sound file." << endl;
      return 1;
   }
   int num_channels = get_unsigned_int2(stream);
   if (num_channels != 1)
   {
      cout << "Not a mono sound file." << endl;
      return 1;
   }

   int sample_rate = get_unsigned_int2(stream);

   stream.seekg(34);
   int bits_per_sample = get_unsigned_int2(stream);
   if (bits_per_sample != 16)
   {
      cout << "Not a 16 bit sound file." << endl;
      return 1;
   }

   // Read data size and allocate data array
   stream.seekg(40);
   int data_size = get_unsigned_int4(stream) / 2; // 2 bytes per data
   int* samples = new int[data_size];

   // Read sound data
   for (int i = 0; i < data_size; i++) 
   {
      samples[i] = get_signed_int2(stream);
   }

   // Process sound data
   process(samples, data_size, sample_rate);

   // Write sound data
   stream.seekp(44);
   for (int i = 0; i < data_size; i++)
   {
      put_signed_int2(stream, samples[i]);
   }

   stream.close();

   delete[] samples;
     
   return 0;
}
