#!/usr/bin/env python
# coding: utf-8

# In[10]:


array_size = input()
array = list(map(int,input().split()))
def increasing_array(array, array_size):
    prev_num = -1
    total_moves = 0
    for num in array:        
        if num <= prev_num:
            moves = prev_num - num
            total_moves += moves
            prev_num = num + moves
        else:
            prev_num = num
    return total_moves
print(increasing_array(array, array_size))

