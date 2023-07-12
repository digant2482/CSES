#!/usr/bin/env python
# coding: utf-8

# In[10]:


string = input()
def permutation_string(string):
    if len(string) <= 1:
        return [string]
    final_list = []
    for idx, letter in enumerate(string):
        new_string = string[:idx] + string[idx+1:]
        p = permutation_string(new_string)
        for word in p:
            final_list.append(letter+word)
    return set(final_list)
final_output = permutation_string(string)
print(len(final_output))
print("\n".join(sorted(final_output)))

