#!/usr/bin/env python
# coding: utf-8

# In[9]:


from collections import deque
num_children = int(input())
array = deque(range(1,num_children+1))
final_list = deque()

while True:
    if len(array) % 2 == 0:
        new_array = deque()
        for idx, num in enumerate(array):
            if idx % 2 == 1:
                final_list.append(num)
            else:
                new_array.append(num)
        array = new_array
    else:
        new_array = deque()
        last_element = array.pop()
        for idx, num in enumerate(array):
            if idx % 2 == 1:
                final_list.append(num)
            else:
                new_array.append(num)
        new_array.appendleft(last_element)
        array = new_array
    if len(array) <= 1:
        final_list.append(array[0])
        break

print(" ".join(map(str, final_list)))

