#ifndef TIME_H
#define TIME_H

class Time
{
public:
   Time();
   Time(int h, int m);
   int get_hours() const;
   int get_minutes() const;
private:
   int hours;
   int minutes;
};

#endif
