# Maximum Gap 
### Question.
<b> Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0. </b>

<br> 
<b> Example 1:</b>

Input: nums = [3,6,9,2]
<br> 
Output: 3
<br> 
Explanation: The sorted form of the array is [2,3,6,9], either (3,6) or (6,9) has the maximum difference 3.



<b> Example 2: </b>

Input: nums = [10]
<br> 
Output: 0
<br> 
Explanation: The array contains less than 2 elements, therefore return 0.
 

<b> Constraints:</b>

1 <= nums.length <= 10^5
<br> 
0 <= nums[i] <= 10^9


<br>

### Approach -1 

```
class Solution {
    public int maximumGap(int[] nums) {
        int maxdiff =Integer.MIN_VALUE;
        
        // returning 0 if the length of the given array is less than 2 
        if(nums.length <2)
            return 0;
                
        // using the sort function to sort given array in ascending order
        Arrays.sort(nums);
        
        for( int i=0; i<nums.length-1;i++){
            // maxdiff = maximum of maxdiff and the diffrence between the consecutive terms in the array
            maxdiff = Math.max(maxdiff, nums[i+1] - nums[i]);
        }
        
        return maxdiff;
        
    }
}
```

### Approach -2 USING BUCKET SORT 

```
class Solution {
    public int maximumGap(int[] nums) {
        if(nums.length < 2) return 0;
        int min = nums[0], max = nums[0];
        for(int i : nums){
            min = Math.min(min, i);
            max = Math.max(max, i);
        }
        int n = nums.length;
        int bucketSize = (max-min)/(n-1);
        if(bucketSize == 0) bucketSize++;
        int totalBuckets = (max-min)/bucketSize + 1;
        
        int[] minBucket = new int[totalBuckets];
        int[] maxBucket = new int[totalBuckets];
        Arrays.fill(minBucket, Integer.MAX_VALUE);
        
        for(int i = 0; i < n; i++){
            int index = (nums[i]-min)/bucketSize;
            minBucket[index] = Math.min(minBucket[index], nums[i]);
            maxBucket[index] = Math.max(maxBucket[index], nums[i]);
        }
        int prevMax = maxBucket[0], result = 0;
        for(int i = 1; i< totalBuckets; i++){
            if(minBucket[i] == Integer.MAX_VALUE)   continue;
            result = Math.max(result, minBucket[i]-prevMax);
            prevMax = maxBucket[i];
        }
        return result;
    }
}


```


### Approach -3 USING RADIX SORT 

```
class Solution {
   public int maximumGap(int[] nums) {
    int max = 0; // the number of sort passes depends on the base of max element
    for(int i = 0; i < nums.length; i++)
        max = Math.max(nums[i], max);

    int divisor = 1;
    int temp[][] = new int[10][nums.length]; // save the elements in ten buckets
    int count[] = new int[10]; // count the size of each bucket
    
    while( divisor <= max ) { // sort the array
        for(int i = 0; i < nums.length; i++) { 
        // put elements into corresponding bucket
            int index = (nums[i] / divisor) % 10;
            temp[index][count[index]] = nums[i];
            count[index]++;
        }

        int current = 0;
        for(int i = 0; i < 10; i++) { // update nums after each turn
            for(int j = 0; j < count[i]; j++) {
                nums[current++] = temp[i][j];
            }
            count[i] = 0;
        }

        divisor *= 10;
    }

    int result = 0;
    for(int i = 1; i < nums.length; i++)
        result = Math.max(nums[i] - nums[i - 1], result);

    return result;
  }
}

```

