#!/usr/bin/env python
# coding: utf-8

# In[46]:


array_size = int(input())
raw_array = input().split()
array = list(map(int, raw_array))
monotonic_stack = [(array[0],1)]
final_array = [0]
 
for idx,num in enumerate(array[1:]):
    idx = idx + 2
    if monotonic_stack[-1][0] >= num:
        while monotonic_stack and monotonic_stack[-1][0] >= num:
            monotonic_stack.pop()
        if not monotonic_stack:
            final_array.append(0)
        else:
            final_array.append(monotonic_stack[-1][1])
    else:
        final_array.append(monotonic_stack[-1][1])
        
    monotonic_stack.append((num,idx))
    
final_array = map(str,final_array)
print(" ".join(final_array))

