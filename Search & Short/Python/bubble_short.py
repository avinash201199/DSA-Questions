# sorting an array using bubble algorithm
def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(i,len(arr)):
            if arr[j] < arr[i]:
                arr[j], arr[i] = arr[i], arr[j]
    
    return arr

print(bubble_sort([3,44,38,5,47,15,36,26,27,2,46,4,19,50,48]))