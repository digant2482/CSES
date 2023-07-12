#!/usr/bin/env python
# coding: utf-8

# In[23]:


n = int(input())
from collections import deque
def gray_code(n):
    m = 2**n -1 
    print("0"*n)
    hashmap = deque()
    hashmap.appendleft("1")
    end_with_zero = False #for any given number hamming distance will be 1 when we append 0 and 1 but two no with hamming distance 1 should have same element appended to maintain hamming distance of 1 
    
    for _ in range(m):
        front = hashmap[-1]
        print("0"*(n-len(front)) + front)
        if end_with_zero:
            hashmap.appendleft(front + "0")
            hashmap.appendleft(front + "1")
            end_with_zero = False
        else:
            hashmap.appendleft(front + "1")
            hashmap.appendleft(front + "0")
            end_with_zero = True
        hashmap.pop()
        
            
gray_code(n)

