import java.util.Arrays;

// Given an array of numbers sorted in increasing order, return a new array containing squares of all the numbers of the input array sorted in increasing order.
// Example- Input: arr[] = [-5, -2, -1, 0, 4, 6]

// Output: [0, 1, 4, 16, 25, 36]


class Main{

public static void main(String[] args) {
    int arr[] = {-5, -2, -1, 0, 4, 6};
     System.out.println(Arrays.toString(arr));
    int outputArr[] = sortedSquares(arr);
    System.out.println(Arrays.toString(outputArr));
}
    public static int[] sortedSquares(int[] nums) {
        int res[]=new int[nums.length];
       int left=0;
       int right=nums.length-1;
       for (int i = nums.length-1; i >=0 ; i--) {
           if (Math.abs(nums[left]) >Math.abs(nums[right])) {
               res[i]=nums[left]* nums[left];
               left++;
           }
           else {
               res[i]=nums[right]*nums[right];
               right--;
           }
       }
       return res;
   }
}