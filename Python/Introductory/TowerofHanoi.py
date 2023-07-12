#!/usr/bin/env python
# coding: utf-8

# In[7]:


num_disks = int(input())
print((2**num_disks)-1) 
def tower_of_hanoi(num_disks, start, end, through):
    if num_disks <= 1:
        print(start, end)
        return
    tower_of_hanoi(num_disks-1, start,through,end)
    print(start,end)
    tower_of_hanoi(num_disks-1, through, end, start)
    
tower_of_hanoi(num_disks, 1,3,2)

