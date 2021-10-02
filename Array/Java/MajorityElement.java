import java.util.Scanner;

/**
 * Majority element is an element which occurs for more than n/2 times in an array where n is the length of the array.
 */
public class MajorityElement {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array");
        int n = sc.nextInt();
        System.out.println("Enter the array elements");
        int i;
        int arr[]= new int[n];
        for(i = 0;i < n ; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();
         int count = 1,element = arr[0];
         for(i = 1; i <n;i++){
             if(arr[i] == element)
                count++;
             else 
                count--;
             
             if(count == 0){
                 element = arr[i];
                 count = 1;
             }
         }
         count = 0;
         //The value in element may or may not be majority element.
         for(i = 0 ; i < n ; i++){
            if(arr[i] == element)
                count++;
         }

         if(count > n/2)
            System.out.println("The majority element is "+element);
         else
            System.out.println("No majority element exists");
    }
    
}

/**
 * Input: 10,5,8,10,10,10,7,10
   Output: 10
   Time Complexity = O(n)
   Space Complexity = O(1)

   Explanation: We maintain two variables where one variable stores the element which occurs the most 
   and the second variable contains the number of occurrences.
   If the array element contains the same value which is present in our element variable, we keep 
   increasing the counter else we decrease the counter.
   If at any point, the counter becomes 0, we change our assumed majority element.
 */