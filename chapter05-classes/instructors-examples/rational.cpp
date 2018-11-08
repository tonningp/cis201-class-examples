#include "rational.h"


Rational Rational::mul(Rational r)
{
    Rational temp;

    temp.set_numerator(m_a * r.m_a);
    temp.set_denominator(m_b * r.m_b);

    return temp;
}
