#!/usr/bin/env python
# coding: utf-8

# In[64]:


n = int(input())
def two_knights(n):
    for i in range(1,n+1):
        print(int(i**2*(i**2-1)/2 - 4*(i-2)*(i-1)))
two_knights(n)

