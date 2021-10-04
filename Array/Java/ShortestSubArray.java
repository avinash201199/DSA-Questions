
/* Input 1: Number of Test cases.
   Input 2: The length of shortest original array.
   Input 3: length number of Array elements
   Input 4: Value of K.*/




import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class ShortestSubArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int  t, n,k;
		int[] arr;
		Solution sn= new Solution();
		Scanner sc= new Scanner(System.in);
		
	    t=sc.nextInt();
	    sc.nextLine();
	    
	    while(t-->0){
	        
	   //	System.out.println("Enter the length of the original array.");
		n= sc.nextInt();
		arr= new int[n];
	
		
	//	System.out.println("Enter array elements:");
		
		for(int i=0; i<n; i++)
			arr[i]= sc.nextInt();
		
	//	System.out.println("Enter the value of K:");
		k= sc.nextInt();
		
	    System.out.println("Length of shortest subarray is "+sn.shortestSubarray(arr, k));
	    
	    }
       
	    sc.close();
	}

}


class Solution {
	
    public int shortestSubarray(int[] A, int K) {
    	
        int N = A.length, res = N + 1;
        int[] S  = new int[N+ 1];
        for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];
        
        Deque<Integer> d = new ArrayDeque<>();
        
        for(int i = 0; i < N + 1; i++){
        	
            while(d.size() > 0 && S[i] - S[d.peekFirst()] >= K){
                res = Math.min(res, i - d.pollFirst()); 
            }
           
            while(d.size() > 0 && S[i] <= S[d.peekLast()]){
                d.pollLast();
            }
            d.offerLast(i);
        }

        return res == N + 1? -1: res;
    }
}
