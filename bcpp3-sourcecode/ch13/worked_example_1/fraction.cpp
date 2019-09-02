#include <cstdlib>
#include "fraction.h"

using namespace std;

int gcd(int a, int b)
{
   int m = abs(a);
   int n = abs(b);
   while (n != 0)
   {
      int r = m % n;
      m = n;
      n = r;
   }
   return m;
}

Fraction::Fraction()
{
   numerator = 0;
   denominator = 1;
}

Fraction::Fraction(int n)
{
   numerator = n;
   denominator = 1;
}

Fraction::Fraction(int n, int d)
{
   int g = gcd(n, d); // The greatest common divisor
   if (g == 0)
   {
      numerator = 0;
      denominator = 1;
   }
   else if (d > 0)
   {
      numerator = n / g;
      denominator = d / g;
   }
   else
   {
      numerator = -n / g;
      denominator = -d / g;
   }
}

Fraction Fraction::operator+(Fraction other) const
{
   return Fraction(numerator * other.denominator
      + denominator * other.numerator,
      denominator * other.denominator);
}

Fraction Fraction::operator*(Fraction other) const
{
   return Fraction(numerator * other.numerator,
      denominator * other.denominator);
}

Fraction operator*(int n, Fraction f)
{
   return f * n;
}

Fraction operator-(Fraction f)
{
   return f * -1;
}

Fraction operator-(Fraction f, Fraction g)
{
   return f + g * -1;
}

Fraction Fraction::inverse() const
{
   return Fraction(denominator, numerator);
}

Fraction operator/(Fraction f, Fraction g)
{
   return f * g.inverse();
}

bool Fraction::operator<(Fraction other) const
{
   return numerator * other.denominator < denominator * other.numerator;
}

bool operator>(Fraction f, Fraction g)
{
   return g < f;
}

bool operator>=(Fraction f, Fraction g)
{
   return !(f < g);
}

bool operator<=(Fraction f, Fraction g)
{
   return !(g < f);
}

bool operator!=(Fraction f, Fraction g)
{
   return f < g || g < f;
}

bool operator==(Fraction f, Fraction g)
{
   return !(f < g || g < f);
}

ostream& operator<<(ostream& out, Fraction f)
{
   f.print(out);
   return out;
}

void Fraction::print(ostream& out) const
{
   out << numerator << "/" << denominator;
}

istream& operator>>(istream& in, Fraction& f)
{
   f.read(in);
   return in;
}

void Fraction::read(istream& in)
{
   in >> numerator;
   char separator;
   in.get(separator); // Read / character
   in >> denominator;
}
