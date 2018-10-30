#!/usr/bin/env python3
import re


def process_answers(d):
    pat = re.compile('^R[0-9]+\.[0-9]+')
    index = 0
    ret = {}
    while index < len(d):
        if pat.match(d[index].rstrip()):
            rq = d[index].rstrip()
            q = []
            index += 1
            while d[index].rstrip() != '---':
                q.append(d[index].rstrip())
                index += 1
            ret[rq]= q
        index += 1
    return ret

with open('answers.txt', 'r') as f:
    data = f.readlines()
    p = process_answers(data)
    print(p)
