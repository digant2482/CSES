#!/usr/bin/env python
# coding: utf-8

# In[17]:


word = input()
from collections import deque
def palindrome_reorder(word):
    
    hash_map = {}
    for letter in word: #O(n)
        if letter not in hash_map:
            hash_map[letter] = 1
        else:
            hash_map[letter] += 1
            
    count = 0
    for letter in hash_map: #O(1)
        if hash_map[letter] % 2 == 1:
            count += 1
            if count > 1:
                print('NO SOLUTION')
                return
            
    left_part = []
    right_part = deque()
    for letter in hash_map: #O(1)
        occurrence = hash_map[letter]
        if occurrence % 2 == 0:
            left_part.append(letter*int(occurrence/2))
            right_part.appendleft(letter*int(occurrence/2))
        else:
            odd_number_letter = letter
    try:
        left_part.append(odd_number_letter*hash_map[odd_number_letter])
    except:
        None
     
    print("".join(left_part) + "".join(right_part))
palindrome_reorder(word)


# In[ ]:




