#!/usr/bin/env python
# coding: utf-8

# In[16]:


n = int(input())
from collections import deque
def gray_code(n):
    m = 2**n -1 
    print("0"*n)
    lenwise_hashmap = {i:deque() for i in range(1,n+2)}
    curr_len = 1
    #When we are changing the lengths (len of binary string the change will result in hamming distance of 1, so numbers after that should be same)
    lenwise_hashmap[curr_len].appendleft("1")
    odd = False #for any given number hamming distance will be 1 when we append 0 and 1 but two no with hamming distance 1 should have same element appended to maintain hamming distance of 1 
    
    for i in range(m):
        if len(lenwise_hashmap[curr_len]):
            front = lenwise_hashmap[curr_len][-1]
            print("0"*(n-len(front)) + front)
            if odd:
                lenwise_hashmap[curr_len + 1].appendleft(front + "0")
                lenwise_hashmap[curr_len + 1].appendleft(front + "1")
                odd = False
            else:
                lenwise_hashmap[curr_len + 1].appendleft(front + "1")
                lenwise_hashmap[curr_len + 1].appendleft(front + "0")
                odd = True
            lenwise_hashmap[curr_len].pop()
        else:
            if curr_len == n:
                break
            curr_len = curr_len+1 
            front = lenwise_hashmap[curr_len][-1]
            print("0"*(n-len(front)) + front)
            if odd:
                lenwise_hashmap[curr_len + 1].appendleft(front + "0")
                lenwise_hashmap[curr_len + 1].appendleft(front + "1")
                odd = False
            else:
                lenwise_hashmap[curr_len + 1].appendleft(front + "1")
                lenwise_hashmap[curr_len + 1].appendleft(front + "0")
                odd = True
            lenwise_hashmap[curr_len].pop()
            
gray_code(n)

