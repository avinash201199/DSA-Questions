// Question : https://leetcode.com/problems/find-in-mountain-array/
/**
 * Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
 * If such an index does not exist, return -1
 */

// Example
/**
 * Example 1:
 * Input: array = [1,2,3,4,5,3,1], target = 3
 * Output: 2
 * Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
 * 
 * Example 2:
 * Input: array = [0,1,2,4,2,1], target = 3
 * Output: -1
 * Explanation: 3 does not exist in the array, so we return -1.
 */

class Solution {
    public static int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = 0;
        int i = 0, j = mountainArr.length()-1;

        // First find out max. height(Peak element) in mountainArr.

        while(i < j) {
            int m = (i + j)/2;

            if(mountainArr.get(m) > mountainArr.get(m+1)) {
                peak = m;
                j = m - 1;
            }
            if(mountainArr.get(m) < mountainArr.get(m+1))
                i = m + 1;
        }

        // Findout the target between 0th index to max. height(peak element).

        int firstHalf = findElement(0, peak, target, mountainArr);
        if(firstHalf != -1)
            return firstHalf;

        // If target element doesn't present in between 0th index to max. height(peak element).
        // Then, findout the target between max. height(peak element) to last index element.

        int secondHalf = findElement(peak, mountainArr.length()-1, target, mountainArr);
        if(secondHalf != -1)
            return secondHalf;

        return -1;
    }

    public static int findElement(int i, int j, int target, MountainArray arr) {

        // Apply Binary search to findout the target element.

        if(i == 0) {
            while(i <= j) {
                int m = (i + j)/2;

                if(arr.get(m) == target)
                    return m;

                if(target > arr.get(m))
                    i = m+1;
                else
                    j = m-1;
            }
        }else {
            while(i <= j) {
                int m = (i + j)/2;

                if(arr.get(m) == target)
                    return m;

                if(target < arr.get(m))
                    i = m+1;
                else
                    j = m-1;
            }
        }

        return -1;
    }
}

// Time complexity : O(log n/2)
// Space complexity : O(1)
