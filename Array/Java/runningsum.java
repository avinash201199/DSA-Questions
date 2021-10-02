// Running Sum of 1d Array

/* 
Write a program that reads an array of nums and outputs the running sum of in the given array of numbers.

Sample Input:
[1,2,3,4]

Sample Output:
[1,3,6,10]

Explanation:
Running sum is obtained as [1, 1+2, 1+2+3, 1+2+3+4] 
*/

class Solution {
    public int[] runningSum(int[] nums) {
        int[] sum=new int[nums.length];
        if(nums.length==0)
            return sum;
        sum[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            sum[i]=sum[i-1]+nums[i];
        }
        return sum;
    }
}
