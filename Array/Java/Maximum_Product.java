
/*
Question : Given the array of integers nums, you will choose two different indices i and j of that array.
           Return the maximum value of (nums[i]-1)*(nums[j]-1).

Language Used : Java

Input : nums = [3,4,5,2]
Output : 12

Input : nums = [1,5,4,5]
Output : 16
*/

class Maximum_Product {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int large = 0, second_large = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > large) {
                second_large = large;
                large = nums[i];
            } 
            else if (nums[i] > second_large) {
                second_large = nums[i];
            }
        }
        return ((large - 1) * (second_large - 1));
    }

}