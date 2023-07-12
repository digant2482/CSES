#!/usr/bin/env python
# coding: utf-8

# In[30]:


array_size = int(input())
array = []
raw_array = input().split()
raw_array = map(int, raw_array)
array = map(lambda s:s%array_size, raw_array)
cum_sum_array = []

total = 0
for num in array:
    total += num
    cum_sum_array.append(total) 
final_array = map(lambda s:s%array_size, cum_sum_array)


cum_sum_dict = {0:1}
count = 0
one_streak = 0

for num in final_array:
    if num == 1:
        one_streak += 1
        continue
    try:
        count += cum_sum_dict[num]
    except:
        None
    try:
        cum_sum_dict[num] += 1
    except:
        cum_sum_dict[num] = 1
        
count += int(one_streak*(one_streak-1)/2)
        
print(count)


# In[ ]:




