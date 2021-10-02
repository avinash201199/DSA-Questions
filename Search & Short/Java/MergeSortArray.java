import java.util.Scanner;

/* Java program for Merge Sort */
public class MergeSortArray{

	// Merges two subarrays of arr[].
	// First subarray is arr[l..m]
	// Second subarray is arr[m+1..r]
	void merge(int arr[], int l, int m, int r){
		// Find sizes of two subarrays to be merged
		int n1 = m - l + 1;
		int n2 = r - m;

		/* Create temp arrays */
		int L[] = new int[n1];
		int R[] = new int[n2];

		/*Copy data to temp arrays*/
		for (int i = 0; i < n1; ++i)
			L[i] = arr[l + i];
		for (int j = 0; j < n2; ++j)
			R[j] = arr[m + 1 + j];

		/* Merge the temp arrays */

		// Initial indexes of first and second subarrays
		int i = 0, j = 0;

		// Initial index of merged subarray array
		int k = l;
		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		/* Copy remaining elements of L[] if any */
		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		/* Copy remaining elements of R[] if any */
		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}

	// Main function that sorts arr[l..r] using
	// merge()
	void sort(int arr[], int l, int r){
		if (l < r) {
			// Find the middle point
			int m =l+ (r-l)/2;

			// Sort first and second halves
			sort(arr, l, m);
			sort(arr, m + 1, r);

			// Merge the sorted halves
			merge(arr, l, m, r);
		}
	}

	/* A utility function to print array of size n */
	static void printArray(int arr[]){
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	// Driver code
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		
		// Input the size of the array
		System.out.println("Enter the size of array: ");
		int size = sc.nextInt();

		// Initialize the array with given size
		int arr[] = new int[size];

		// Input the array elements
		System.out.println("Enter array elements");
		for (int i = 0; i < size; i++)
			arr[i] = sc.nextInt();

		//Close the scanner after taking input
		sc.close();
		
		//Print the given array
		System.out.println("Given Array is");
		printArray(arr);

		MergeSortArray ob = new MergeSortArray();
		ob.sort(arr, 0, arr.length - 1);

		//Output the sorted array
		System.out.println("\nSorted array");
		printArray(arr);
	}
}
/*
 * Java program for Implementation of Merge Sort 
 * Input: Size of array,array of integers 
 * Output: Sorted array in ascending order
 * ---------------------------------------- 
 * Sample Input: 
 * 4
 * 25 9 49 16
 * Output:
 * Given Array is
 * 25 9 49 16 
 * Sorted array
 * 9 16 25 49 
 * ---------------------------------------- 
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 */
