#!/usr/bin/env python
# coding: utf-8

# In[93]:


from collections import deque
def split_and_sort(string):
    start = 0
    result = []
    while start < len(string):
        idx = string.find(" ", start)
        if idx != -1:
            result.append(int(string[start:idx]))
            start = idx + 1
        else:
            result.append(int(string[start:]))
            break
    return deque(sorted(result))
       
num_children, max_wght = list(map(int,input().split(" ")))
child_list = split_and_sort(input())
def ferris_wheel(child_list, max_wght):
    count = 0
    while child_list:
        if child_list[-1] != child_list[0]:
            if child_list[-1] + child_list[0] <= max_wght:
                child_list.pop()
                child_list.popleft()
                count += 1
            else:
                child_list.pop()
                count += 1
        elif len(child_list) != 1:
            while len(child_list) != 1 and len(child_list) != 0:
                if 2*child_list[-1] <= max_wght:
                    child_list.pop()
                    child_list.popleft()
                    count += 1
                else:
                    child_list.pop()
                    count += 1   
        else:
            count += 1
            break
    print(count)
      
ferris_wheel(child_list, max_wght)  


# In[ ]:




