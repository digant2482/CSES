#!/usr/bin/env python
# coding: utf-8

# In[11]:


array_size, threshold = [int(i) for i in input().split()]
raw_array = input().split()
array = list(map(int, raw_array))
distinct_values = {}
i,j = 0,0
count = 0

while i < array_size:
    if j == array_size:
        count += j-i
        distinct_values[array[i]] -= 1  
        i += 1
        continue
        
    if array[j] not in distinct_values:
        distinct_values[array[j]] = 1
    else:
        distinct_values[array[j]] += 1
    
    while len(distinct_values) > threshold:
        count += j-i
        distinct_values[array[i]] -= 1
        if distinct_values[array[i]] == 0:
            del distinct_values[array[i]]
        i += 1
     
    if j < array_size:
        j += 1
print(count)

