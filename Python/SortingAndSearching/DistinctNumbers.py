#!/usr/bin/env python
# coding: utf-8

# In[42]:


n = int(input())
li = input().split(" ")
def distinct_numbers(n, li):
    hash_map = {}
    count = 0
    for num in li:
        try:
            if hash_map[num]:
                continue
        except:
            hash_map[num] = True
            count += 1
    print(count)  
distinct_numbers(n, li)

