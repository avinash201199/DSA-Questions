/*
Quick sort sometimes called as partition exchange sort, an efficient sorting algorithm.
The three steps of quick sort algorithm are as follows :

Divide: Rearrange the elements and split the array into two subarrays and an element in
between them(known as pivot) such that each element in the left subarray is less than or equal to
pivot element and each element in the right subarray is greater than the pivot element.

Conquer: Recursively sort the two subarrays.

Combine: The solution of sub-problems to create a solution to the original problem.

Input : 1. Number of test cases
        2. The length of the array.
        3. Array elements
 */

import java.util.Scanner;

public class QuickSort {

	public static void main(String[] args){

		int[] arr;
		int n,t;
		Scanner sc= new Scanner(System.in);
		t= sc.nextInt();
		sc.nextLine();

		while(t-->0){

			n= sc.nextInt();
			arr= new int[n];

			for(int i=0; i<n;i++)
				arr[i]= sc.nextInt();

			System.out.println("Before sort: ");
			display(arr);

			quickSort(arr,0,n-1);
			System.out.println("After sort: ");
			display(arr);
			System.out.println("---------------------------------");


		}
	}

	private static void quickSort(int[] arr,int low, int high) {

		int pi= partition(arr,low,high);

		if(low<pi-1){
			quickSort(arr,low,pi-1); // sort the left sub array
		}
		else if(pi<= high){
			quickSort(arr,pi,high); // sort the right sub array
		}
	}

	private static int partition(int[] arr, int low, int high){

		// find the pivot
		int pivot= arr[(low+high)/2];

		while(low<=high){

			while(arr[low]<pivot){
				low++;
			}
			while(arr[high]>pivot){
				high--;
			}

			// swap the elements present in low and high position
			if(low<=high){

				int temp= arr[low];
				arr[low]= arr[high];
				arr[high]= temp;

				// increment and decrement low and high value
				low++;
				high--;
			}


		}
		return low;
	}

	private static void display(int[] arr) {

		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
}
