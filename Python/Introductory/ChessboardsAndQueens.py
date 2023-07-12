#!/usr/bin/env python
# coding: utf-8

# In[7]:


from itertools import permutations
reserved_squares = []
for row in range(8):
    column = list(input())
    for col, element in enumerate(column):
        if element == '*':
            reserved_squares.append((row, col))
            

possible_permutations = permutations(range(8))

count = 0

for permutation in possible_permutations:
    valid = True
    right_diagonal = [False]*15
    left_diagonal = [False]*15
    for row_idx, col_idx in enumerate(permutation):
        
        right_diagonal_sum = 7 + col_idx - row_idx
        if right_diagonal[right_diagonal_sum]:
            valid = False
            break
        else:
            right_diagonal[right_diagonal_sum] = True
            
        left_diagonal_sum = col_idx + row_idx
        if left_diagonal[left_diagonal_sum]:
            valid = False
            break
        else:
            left_diagonal[left_diagonal_sum] = True

        if (row_idx, col_idx) in reserved_squares:
            valid = False
            break
    count += valid
print(count)

