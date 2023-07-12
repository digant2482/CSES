#!/usr/bin/env python
# coding: utf-8

# In[73]:


n = int(input())
def bit_strings(n):
    print(2**n % (10**9 + 7))
bit_strings(n)

