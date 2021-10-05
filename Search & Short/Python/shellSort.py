# Shell sort in python

def shellSort(array, n):

    # Rearrange elements at each n/2, n/4, n/8, ... intervals
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = array[i]
            j = i
            while j >= interval and array[j - interval] > temp:
                array[j] = array[j - interval]
                j -= interval

            array[j] = temp
        interval //= 2

def printList(arr):
	for i in range(len(arr)):
		print(arr[i], end=" ")
	print()

if __name__ == '__main__':

	x = list(map(int,input("Enter the list of numbers separated by space: ").split()))
	print("Given array is", end="\n")
	printList(x)
	size = len(x)
	shellSort(x, size)
	print("Sorted array is: ", end="\n")
	printList(x)

# This code is contributed by Yasas Sandeepa
'''
Input:  x = 1 5 20 3 12 4
Output: x = 1 3 4 5 12 20
Average Time complexity: O(nlogn)
Space complexity: O(1)
'''
