#!/usr/bin/env python
# coding: utf-8

# In[ ]:


n = int(input())
def coin_piles(tup):
    a, b = tup
    if b > a:
        if b - a <= a and (b - 2*a)%3 == 0:
            print('YES')
        else:
            print("NO")
    else:
        if a - b <= b and (a - 2*b)%3 == 0:
            print('YES')
        else:
            print('NO')
for i in range(n):
    tup = tuple(map(int,input().split(" ")))
    coin_piles(tup)

