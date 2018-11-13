#include<vector>
#include "point.h"

void print(std::vector<Point> &pts)
{
    for(int i=0;i < pts.size();i++)
       pts[i].print();
}

int main()
{
   std::vector<Point>  points;
   points.push_back(Point("point1",1,1));
   points.push_back(Point("point2",1,2));
   points.push_back(Point("point3",0,1));
   points.push_back(Point("point4",0,2));
   
   print(points);

   return 0;
}
