#!/usr/bin/env python
# coding: utf-8

# In[1]:


to_search = input()
def repetitions(to_search):
    max_repetition = 0
    freq_counter = 1
    prev_letter = None
    for curr_letter in to_search:
        if prev_letter == curr_letter:
            freq_counter += 1
        else:
            if max_repetition < freq_counter:
                max_repetition = freq_counter
            freq_counter = 1
        if max_repetition < freq_counter:
            max_repetition = freq_counter
        prev_letter = curr_letter  
    return max_repetition
print(repetitions(to_search))


# In[ ]:




