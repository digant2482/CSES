#!/usr/bin/env python
# coding: utf-8

# In[14]:


i = int(input())
def weird_algorithm(n):
    result = f"{n}"
    while n != 1:
        if n % 2 == 0:
            n = int(n/2)
            result = result + f' {n}'
        else:
            n = n*3 + 1
            result = result + f' {n}'
    return result
print(weird_algorithm(i))

