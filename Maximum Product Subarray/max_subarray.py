# Python 3 program to find maximum
# product subarray
 
# Function to find maximum
# product subarray
def maxProduct(arr, n):
     
    # Variables to store maximum and
    # minimum product till ith index.
    minVal = arr[0]
    maxVal = arr[0]
 
    maxProduct = arr[0]
 
    for i in range(1, n, 1):
         
        # When multiplied by -ve number,
        # maxVal becomes minVal
        # and minVal becomes maxVal.
        if (arr[i] < 0):
            temp = maxVal
            maxVal = minVal
            minVal = temp
             
        # maxVal and minVal stores the
        # product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i])
        minVal = min(arr[i], minVal * arr[i])
 
        # Max Product of array.
        maxProduct = max(maxProduct, maxVal)
 
    # Return maximum product
    # found in array.
    return maxProduct
 
# Driver Code
if __name__ == '__main__':
    arr = [-1, -3, -10, 0, 60]
 
    n = len(arr)
 
    print("Maximum Subarray product is",
                     maxProduct(arr, n))