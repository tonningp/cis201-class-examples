#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction
{
public:
   /**
      Constructs a fraction n / d.
      @param n the numerator
      @param d the denominator
   */
   Fraction(int n, int d);
   /**
      Constructs a fraction n / 1.
      @param n the numerator
   */
   Fraction(int n);
   /**
      Constructs the fraction 0 / 1.
   */
   Fraction();
   
   /**
      Comoutes the inverse of this fraction.
      @return the inverse (denominator / numerator)
   */
   Fraction inverse() const;
   /**
      Prints this fraction to a stream.
      @param out the output stream
   */
   void print(ostream& out) const;
   /**
      Reads a fraction from a stream and stores the input 
      in this fraction.
      @param in the input stream
   */
   void read(istream& in);

   Fraction operator+(Fraction other) const; 
   Fraction operator*(Fraction other) const;
   bool operator<(Fraction other) const;
private:
   int numerator;
   int denominator;
};

Fraction operator-(Fraction f);
Fraction operator-(Fraction f, Fraction g);
Fraction operator*(int n, Fraction f);
Fraction operator/(Fraction f, Fraction g);
bool operator>(Fraction f, Fraction g);
bool operator<=(Fraction f, Fraction g);
bool operator>=(Fraction f, Fraction g);
bool operator==(Fraction f, Fraction g);
bool operator!=(Fraction f, Fraction g);
ostream& operator<<(ostream& out, Fraction f);
istream& operator>>(istream& in, Fraction& a);
   
#endif
