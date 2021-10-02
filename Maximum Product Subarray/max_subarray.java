// Java program to find maximum product subarray
import java.io.*;
 
class GFG {
 
    // Function to find maximum product subarray
    static int maxProduct(int arr[], int n)
    {
         
        // Variables to store maximum and minimum
        // product till ith index.
        int minVal = arr[0];
        int maxVal = arr[0];
     
        int maxProduct = arr[0];
     
        for (int i = 1; i < n; i++)
        {
     
            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (arr[i] < 0)
            {
                int temp = maxVal;
                maxVal = minVal;
                minVal =temp;
             
            }
     
            // maxVal and minVal stores the
            // product of subarray ending at arr[i].
            maxVal = Math.max(arr[i], maxVal * arr[i]);
            minVal = Math.min(arr[i], minVal * arr[i]);
     
            // Max Product of array.
            maxProduct = Math.max(maxProduct, maxVal);
        }
     
        // Return maximum product found in array.
        return maxProduct;
    }
     
    // Driver Code
    public static void main (String[] args)
    {
        int arr[] = { -1, -3, -10, 0, 60 };
        int n = arr.length;
     
        System.out.println( "Maximum Subarray product is "
                                    + maxProduct(arr, n));
    }
}
 