#!/usr/bin/env python
# coding: utf-8

# In[1]:


from collections import defaultdict
import sys
num_movies = int(input())
arrival = defaultdict(int)
departure = defaultdict(int)
lines = sys.stdin.readlines()
for line in lines:
  start,end = line.split()
  arrival[int(start)] += 1
  departure[int(end)] += 1
 
arrival_keys = sorted(arrival.keys())
departure_keys = sorted(departure.keys())
max_persons = arrival[arrival_keys[0]]
curr_person_count = arrival[arrival_keys[0]]
 
arrival_keys_iter = iter(arrival_keys)
departure_keys_iter = iter(departure_keys) 
next(arrival_keys_iter)
curr_arrival_key = next(arrival_keys_iter)
curr_departure_key = next(departure_keys_iter)
arrival_index = 1
while True:
  if curr_arrival_key < curr_departure_key:
    curr_person_count += arrival[curr_arrival_key]
    if max_persons < curr_person_count:
      max_persons = curr_person_count
    if arrival_index == len(arrival_keys) - 1:
      break
    curr_arrival_key = next(arrival_keys_iter)
    arrival_index += 1
  elif curr_arrival_key > curr_departure_key:
    curr_person_count -= departure[curr_departure_key]
    curr_departure_key = next(departure_keys_iter)
  else:
    curr_person_count += arrival[curr_arrival_key]
    curr_person_count -= departure[curr_departure_key]
    if max_persons < curr_person_count:
      max_persons = curr_person_count
    curr_arrival_key = next(arrival_keys_iter)
    arrival_index += 1
    curr_departure_key = next(departure_keys_iter)
print(max_persons)

