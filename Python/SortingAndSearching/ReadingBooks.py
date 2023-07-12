#!/usr/bin/env python
# coding: utf-8

# In[3]:


num_books = int(input())
time_required = sorted(map(int,input().split()))
sum_time_required = sum(time_required)

total_time_i = time_required[0]
total_time_j = time_required[-1]
i,j = 0,num_books-1
if sum(time_required[:-1]) < total_time_j:
    print(2*total_time_j)
else:
    while i < num_books and j > 0:
        while total_time_i < total_time_j and i+1 < j:
            i+=1
            total_time_i += time_required[i]

        while total_time_i >= total_time_j and i+1 < j:
            j-=1
            total_time_j += time_required[j]

        if i+1 == j:
            if total_time_i <= total_time_j:
                print(sum_time_required)
                break
            else:
                if (total_time_i-time_required[i]) < (time_required[i] - (total_time_j-(total_time_i-time_required[i]))):
                    print(sum_time_required + (time_required[i] - (total_time_j-(total_time_i-time_required[i]))) - (total_time_i-time_required[i]))
                    break
                else:
                    print(sum_time_required)
                    break

