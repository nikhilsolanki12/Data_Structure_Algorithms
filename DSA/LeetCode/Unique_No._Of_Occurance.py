# Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
# Example 1:
# Input: arr = [1,2,2,1,1,3]
# Output: true
# Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
      t=dict()
      s=set(arr)
    #   if len(s)==len(arr):
    #     return False
      for i in s:
        t[i]=arr.count(i)
        # t[arr.count(i)]=i
      print(list(t.keys()))
      if len(set(t.values()))==len(list(t.values())):
         return True
      else:
          return False 