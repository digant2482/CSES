#!/usr/bin/env python
# coding: utf-8

# In[46]:


from collections import deque
num_apples = int(input())
array = [int(i) for i in input().split()]
total = sum(array)
min_difference = 1e18
binary_storage = deque(['0'*(num_apples-1) + '1'])

for num in range(2**num_apples - 1):
    front = binary_storage[-1]
    binary_storage.appendleft(front[1:] + '0')
    binary_storage.appendleft(front[1:] + '1')
    binary = binary_storage.pop()
    subtotal = 0
    for idx in range(num_apples):
        if binary[idx] == '0':
            subtotal += array[idx]
    difference = abs(total - 2*subtotal)
    min_difference = min(min_difference,difference)
print(min_difference)

