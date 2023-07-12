#!/usr/bin/env python
# coding: utf-8

# In[8]:


import sys
num_ranges = int(input())
array = sorted([list(map(int,line.split())) + [idx] for idx,line in enumerate(sys.stdin.readlines())],key = lambda s:(s[0],-s[1]))

contains = ['0']*num_ranges
contained = ['0']*num_ranges

max_right_boundary = -1e18
#contained
for tup in array:
    curr_right_boundary = tup[1]
    if max_right_boundary >= curr_right_boundary:
        contained[tup[2]] = "1"
        
    if curr_right_boundary > max_right_boundary:
        max_right_boundary = curr_right_boundary
        
#contains
min_right_boundary = 1e18
for tup in array[::-1]:
    curr_right_boundary = tup[1]
    if min_right_boundary <= curr_right_boundary:
        contains[tup[2]] = '1'

    if curr_right_boundary < min_right_boundary:
        min_right_boundary = curr_right_boundary
    
print(" ".join(contains))    
print(" ".join(contained))

