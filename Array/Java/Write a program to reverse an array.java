/* Given an array A of size N, print the reverse of it.
Input:
First line contains an integer denoting the test cases 'T'. T testcases follow. Each testcase contains two lines of input. First line contains N the size of the array A. The second line contains the elements of the array.
Output:
For each testcase, in a new line, print the array in reverse order.
Constraints:
1 <= T <= 100
1 <= N <=100
0 <= Ai <= 100
Example:
Input:
1
4
1 2 3 4
Output:
4 3 2 1
*/

import java.util.*;
import java.lang.*;
import java.io.*;
class Reverse {
    public void rotate(int[] nums, int k) {
        int size = nums.length;
        for (int i = 0; i < k; i++) {
            int lastVal = nums[size - 1];
            for (int j = size - 2; j >= 0; j--)
                nums[j + 1] = nums[j];
            nums[0] = lastVal;
        }
    }
}
