/*
Question : Peak Index in a Mountain Array

Let's call an array arr a mountain if the following properties hold:
  1)  arr.length >= 3
  2)  There exists some i with 0 < i < arr.length - 1 such that:
           arr[0] < arr[1] < ... arr[i-1] < arr[i]
           arr[i] > arr[i+1] > ... > arr[arr.length - 1]

Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[i] is the peak.


Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [3,4,5,1]
Output: 2

Language Used : Java

Approach Used : Binary Search
*/

class Peak_Index {
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0, end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return mid;

            else if (arr[mid] < arr[mid + 1])
                start = mid + 1;

            else
                end = mid - 1;
        }
        return 0;
    }
}
