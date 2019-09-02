#include <iostream>
#include <cmath>

using namespace std;
                   
int main()
{      
   cout << "Distance to item along x-axis: ";
   double x_distance;
   cin >> x_distance;
   cout << "Distance to item along y-axis: ";
   double y_distance;
   cin >> y_distance;
   cout << "Length of segment 1: ";
   double segment1_length;
   cin >> segment1_length;
   cout << "Speed along segment 1: ";
   double segment1_speed;
   cin >> segment1_speed;
   cout << "Speed along segment 2: ";
   double segment2_speed;
   cin >> segment2_speed;

   double segment1_time = segment1_length / segment1_speed;
   double segment2_length = sqrt(pow(x_distance, 2)
      + pow(y_distance - segment1_length, 2));
   double segment2_time = segment2_length / segment2_speed;
   double total_time = segment1_time + segment2_time;

   cout << "Total time: " << total_time << endl;
   return 0;
}
