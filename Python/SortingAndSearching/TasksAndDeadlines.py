#!/usr/bin/env python
# coding: utf-8

# In[60]:


import sys
num_tasks = int(input())
tasks = [tuple(map(int,line.split())) for line in sys.stdin.readlines()]
sorted_tasks = sorted(tasks, key = lambda s : (s[0],-s[1]))

points = 0
time = 0
for task in sorted_tasks:
    points += task[1] - (time+task[0])
    time += task[0]
print(points)

