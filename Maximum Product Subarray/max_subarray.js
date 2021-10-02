<script>
// Javascript program to find maximum product subarray
     
    // Function to find maximum product subarray
    function maxProduct(arr,n)
    {
        // Variables to store maximum and minimum
        // product till ith index.
        let minVal = arr[0];
        let maxVal = arr[0];
       
        let maxProduct = arr[0];
       
        for (let i = 1; i < n; i++)
        {
       
            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (arr[i] < 0)
            {
                let temp = maxVal;
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
    let arr=[ -1, -3, -10, 0, 60 ];
    let n = arr.length;
    document.write( "Maximum Subarray product is "
                                    + maxProduct(arr, n));