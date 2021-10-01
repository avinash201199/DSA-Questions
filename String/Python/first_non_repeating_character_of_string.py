"""
Question: Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Input: s = "aabb"
Output: -1
Input: s = "code"
Output: 0

Language used: Python

Here we will simply use Counter that will help us in counting the elements of the string.
Then we will run a loop that will run till we find the first non-repeating character
"""

from collections import Counter

# take a string as an input
str=input() 
count=Counter(str)

for i in str:
    if count[i]==1:
        index_of=i
        break
    else:
        index_of=-1

#printing the answer

print(-1) if index_of==-1 else print(str.index(index_of))