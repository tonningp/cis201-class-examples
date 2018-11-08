#include<iostream>


class A
{
   int m_data;
public:
    A();
    A(int data)

    A makeA();
}

A::A()
{
    m_data = 0;
}

A::A(int data)
{
    m_data = data;
}

A A::makeA()
{
    return A(10);
}
