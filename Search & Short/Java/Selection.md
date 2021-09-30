# Sorting
## Selection Sort

``` java
package sorting;
import java.util.*;
  public class SelectionSort {
	static void swap(int a[],int i,int j) {
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	static void selection(int a[],int n) {
		for(int i=0;i<n;i++) {
			int minindex=i;
			for(int j=i+1;j<n;j++) {
				if(a[j]<a[minindex]) {
					minindex=j;
				}
			}
			swap(a,minindex,i);
			
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		int a[]= {9,3,7,1,6};
		int n=a.length;
		selection(a,n);
		for(int i=0;i<n;i++) {
		System.out.println(a[i]);
		}
	}
}
```
### Time Complexity:theta(n^2).
### It does less memory wrights compare to other algorithm.
### selection sort is an in-place algorithm does not require extra memory.
## Basic Idea of Algorithm 
#### In this Algorithm first we find the lowest value in the array then will swap it to the minimum possible position this cycle keeps repeating until we get an sorted array.  
