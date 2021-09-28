/* Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 
*/

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int i,count=0,result=0;
        for(i=0;i<nums.length;i++)
        {
            if(nums[i]==0)
            {
                count=0;
            }
            else 
            {
                count++;
                result=Math.max(count,result);
            }
        }
        return result;
    }
}
