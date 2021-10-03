# count
def InvCount(arr, n):
   inv_count = 0
   for i in range(n):
      for j in range(i + 1, n):
         if (arr[i] > arr[j]):
            inv_count += 1
   return inv_count
# Driver Code
arr = [1,5,3,8,7]
n = len(arr)
print("Total number of inversions are:",InvCount(arr, n))
