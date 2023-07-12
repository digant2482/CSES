#!/usr/bin/env python
# coding: utf-8

# In[14]:


array_size = int(input())
def permutations(array_size):
    if array_size == 3 or array_size == 2:
        print('NO SOLUTION')
    else:
        for i in range(2,array_size + 1,2):
            print(i, end= " ")
        for i in range(1,array_size + 1,2):
            print(i, end=" ")
            
permutations(array_size)

