#!/usr/bin/env python3

def gcd(a, b):
    while b != 0:
       t = b 
       b = a % b 
       a = t
    return a

def rgcd(a, b):
    if b == 0:
        return a
    else:
        return rgcd(b,a % b)


print(gcd(124,240))
print(rgcd(124,240))
