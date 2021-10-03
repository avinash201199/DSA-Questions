/* Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.
Example 1:
Input:
N = 5
A[] = {1,2,3,5}
Output: 4
Example 2:
Input:
N = 10
A[] = {6,1,2,8,3,4,7,10,5}
Output: 9
*/

class Solution {
    int MissingNumber(int array[], int n) {
        // Your Code Here
         Arrays.sort(array);
       int num =n;
      for(int i=1;i<n;i++){
          if(array[i-1]!=i){
              return i;
          }
  
      }
      return num;
    }
}
