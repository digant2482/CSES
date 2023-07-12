#!/usr/bin/env python
# coding: utf-8

# In[ ]:


array_size, target_sum = [int(i) for i in input().split()]
array = [int(i) for i in input().split()]
num_at_i = array[0]

count = 0
total = 0
i,j = 0,0
for num_at_j in array:
    j += 1
    total += num_at_j
    
    if total >= target_sum:
        if total == target_sum:
            count += 1    
        while total >= target_sum and i < j:
            i += 1
            total -= num_at_i
            if i < array_size:
                num_at_i = array[i]
            if total == target_sum:
                count += 1
print(count)

