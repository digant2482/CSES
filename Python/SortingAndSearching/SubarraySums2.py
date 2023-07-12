#!/usr/bin/env python
# coding: utf-8

# In[2]:


array_size, target_sum = [int(i) for i in input().split()]
array_raw = list(map(int,input().split()))
count = 0
cum_sum_dict = {}

if array_raw[0] != 0:
    cum_sum_dict = {0:1}
    
cum_sum = 0
for num_at_j in array_raw:
    if target_sum != 0 and not num_at_j and cum_sum == target_sum:
        count += 1
        continue
    cum_sum += num_at_j
    try:
        cum_sum_dict[cum_sum] += 1
    except:
        cum_sum_dict[cum_sum] = 1 
    try:
        count += cum_sum_dict[cum_sum - target_sum]
    except:
        None
print(count)

