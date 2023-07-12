#!/usr/bin/env python
# coding: utf-8

# In[32]:


num_tests = int(input()) 
tests = []
for test in range(num_tests):
    tests.append(tuple(map(int,input().split())))

def number_spiral(tup):
    row, col = tup
    if row == col:
        final_element = (row)**2 - (row-1)
        
    elif row > col: #The element can be found in that row
        if row % 2 == 0:
            first_element = (row)**2
            final_element = first_element - (col-1)
        else:
            first_element = (row-1)**2 + 1
            final_element = first_element + (col-1)
    
    else:
        if col % 2 == 0:
            first_element = (col-1)**2 + 1
            final_element = first_element + (row-1)
        else:
            first_element = (col)**2  
            final_element = first_element - (row-1)
    return final_element

for test in tests:
    print(number_spiral(test))

