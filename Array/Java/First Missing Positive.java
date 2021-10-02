// Question : https://leetcode.com/problems/first-missing-positive/

// Example
/**
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 * 
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * 
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 */

import java.util.*;

class Solution {
    public static int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // First of all the elements using Cyclic sort.

        for(int i = 0; i < n; i++)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int temp1 = nums[i];
                int temp2 = nums[nums[i] - 1];
                nums[i] = temp2;
                nums[temp1 - 1] = temp1;
            }

        // Lastly, check weather th element is present or not.

        for(int j = 0; j < n; j++)
            if(nums[j] != j + 1)
                return j + 1;

        return n + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] nums = new int[n];
        
        for(int i = 0; i < n; i ++)
            nums[i] = sc.nextInt();
        
        System.out.println( firstMissingPositive(nums) );

        sc.close();
    }
}

// Time complexity : O(n)
// Space complexity : O(1)