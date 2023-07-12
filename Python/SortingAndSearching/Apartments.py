#!/usr/bin/env python
# coding: utf-8

# In[25]:


n,m,k = map(int,input().split(" "))
desired_size = map(int,sorted(input().split(" "), key = lambda s: (len(s), s)))
avlble_size = map(int,sorted(input().split(" "), key = lambda s: (len(s), s)))
def apartments(n,m,k,desired_size, avlble_size):
    count = 0
    des_size = next(desired_size)
    size = next(avlble_size)
    while m and n:
        
        if size < (des_size - k):
            while size < (des_size - k):
                m -= 1
                if m:
                    size = next(avlble_size)
                else:
                    break
                    
        elif size > (des_size + k):
            while size > (des_size + k):
                n -= 1
                if n:
                    des_size = next(desired_size) 
                else:
                    break
                    
        elif (des_size - k) <= size and size <= (des_size + k):
            count += 1
            m -= 1
            n -= 1
            if m and n:
                des_size = next(desired_size)
                size = next(avlble_size)  
            else:
                break
    print(count)
apartments(n,m,k,desired_size,avlble_size)

