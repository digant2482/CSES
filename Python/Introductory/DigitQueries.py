#!/usr/bin/env python
# coding: utf-8

# In[31]:


import sys
from decimal import Decimal
num_queries = int(input())
queries_array = []
for i in range(num_queries):
    queries_array.append(Decimal(input()))
for k in queries_array:
    if k <= 9:
        print(k)
    else:
        path_traversed = Decimal(9)
        nines = Decimal(9)
        digits = Decimal(1)
        while path_traversed < k: 
            nines *= Decimal(10)
            digits += Decimal(1)
            path_traversed += Decimal(nines*digits)  
        else:
            path_traversed -= Decimal(nines*digits)  
            nines /= Decimal(10)
            digits -= Decimal(1)
            
            
        num_after_traversal = Decimal(10**(digits)) 
        digits = digits+Decimal(1)
        if ((k-path_traversed)/digits).as_integer_ratio()[1] == 1:
            desired_number = ((k-path_traversed)/digits) - 1 + num_after_traversal
            print(str(int(desired_number))[-1])
        else:
            #penultimate number = ((k-path_traversed)//digits) -1 + num_after_traversal
            desired_number = ((k-path_traversed)//digits) + num_after_traversal
            path_traversed += ((desired_number-1)-num_after_traversal + 1)*digits
            position_digit = k - path_traversed
            print(str(desired_number)[int(position_digit-1)])     

