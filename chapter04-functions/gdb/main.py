#!/usr/bin/env python3

def factorial(n):
    result = 1
    while n > 0:
        result *= n
        n -= 1
    return result

print(factorial(1000))
