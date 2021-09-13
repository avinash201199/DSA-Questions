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

class GFG {
	public static void main (String[] args) {
		//code
		Scanner input=new Scanner(System.in);
		int t=input.nextInt();
		for(int i=0;i<t;i++)
		{
		  int n=input.nextInt();
		  int[] array= new int[n];
		  for(int j=0;j<n;j++)
		  {
		      array[j]=input.nextInt();
		  }
		  
		 for(int k=n-1;k>=0;k--){
		    System.out.print(array[k] + " ");  
	   
		}
		System.out.println();
		}
		
	}
}
