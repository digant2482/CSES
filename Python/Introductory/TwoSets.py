#!/usr/bin/env python
# coding: utf-8

# In[61]:


n = int(input())
def two_sets(n):
    if (n*(n+1)/4).is_integer():
        print('YES')
        left = []
        right = []
        target = (n*(n+1))/4
        for i in range(n,0,-1):
            if i <= target:
                right.append(i)
                target -= i
            else:
                left.append(i)
            
        print(len(left))  
        print(*left)
        print(len(right))
        print(*right)    
    else:
        print("NO")
    
two_sets(n)

