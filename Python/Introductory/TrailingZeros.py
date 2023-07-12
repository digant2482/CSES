#!/usr/bin/env python
# coding: utf-8

# In[84]:


n = int(input())
def trailing_zeros(n):
    num_five_factors = 0
    curr_divider = 5
    while n//curr_divider != 0:
        num_five_factors += n//curr_divider
        curr_divider = curr_divider*5
    print(num_five_factors)
trailing_zeros(n)

