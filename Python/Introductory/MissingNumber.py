#!/usr/bin/env python
# coding: utf-8

# In[30]:


to_search = int(input())
search_from = input()
def missing_number(to_search, search_from):
    search_from = [int(i) for i in search_from.split(" ")]
    return sum(range(1, to_search + 1)) - sum(search_from)
print(missing_number(to_search, search_from))

