#!/usr/bin/env python
# coding: utf-8

# In[1]:


from collections import defaultdict
array_size = int(input()) 

array = [int(i) for i in input().split()]

if len(array) <= 1:
    print(1)
else:
    song_at_i = array[0]
    max_total = 0
    i,j = 0,0

    song_listened = defaultdict(bool)

    while i < array_size - 1 and j < array_size - 1:
        j += 1 
        song_at_j = array[j]
       
        if song_listened[song_at_j]:
            while array[i] != song_at_j:
                song_listened[array[i]] = False
                i += 1
                song_at_i = array[i] 
        else:
            song_listened[song_at_j] = True
            
        if song_at_j == song_at_i:
            i += 1
            if i < array_size:
                song_at_i = array[i]  
                
        difference = j - i + 1

        if max_total < difference:
            max_total = difference 

    if difference and max_total < difference:
        max_total = difference

    print(max_total)

