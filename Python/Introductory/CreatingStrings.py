#!/usr/bin/env python
# coding: utf-8

# In[12]:


word = list(input())
from itertools import permutations
def creating_string(word):
    count = 0
    for _ in set(permutations(word)):
        count += 1
    print(count)
    for p in sorted(set(permutations(word))):
        print("".join(p))
creating_string(word)

