/*
  Java program
  Interpolation Sort

Theory :
--------------
Interpolation sort is a kind of bucket sort. It uses an interpolation formula to assign data to the bucket. A general interpolation formula is:
Interpolation = INT(((Array[ i ] - min) / (max - min)) * (ArraySize -1))

Class : Sorting Algorithm
Data structure : Array

Worst-case performance : O(n^2)
Best-case performance: O(n)
Average performance : O(n+k)

*/
import java.util.*;
public class InterpolationSort {

	// Display elements of given sequence

	public static void display(int[] sequence, int size) {
		for (int i = 0; i < size; ++i) {
			System.out.print("  " + sequence[i]);
		}
		System.out.print("\n");
	}


	// Sort elements using interpolation sort

	public static void interpolationSort(int[] sequence, int size) {

		if (size <= 0) {
			return;
		}

		int start = 0;
		int end = size;
		int location = 0;
		int slot = 0;

		// Loop controlling variables
		int i = 0;
		int j = 0;

		// Define min max variable
		int min = 0;
		int max = 0;

		ArrayList<Integer> process = new ArrayList<Integer>();
		ArrayList<ArrayList<Integer>> bucket = new ArrayList<ArrayList<Integer>>();

		// Assign the memory of each slot

		for (i = 0; i < size; ++i) {
			// Allocate memory
			bucket.add(new ArrayList<Integer>());
		}

		// Add the size of array
		process.add(size);

		while (process.size() > 0) {

			// Get last size

			location = process.get(process.size() - 1);

			// Remove the last element of process
			process.remove(process.size() - 1);

			// Get start location
			start = end - location;

			// Get starting element
			max = sequence[start];
                                                      min = sequence[start];

			// Find minimum and maximum
			for (i = start + 1; i < end; i++) {

				if (sequence[i] > max) {
					max = sequence[i];
				} else if (sequence[i] < min) {
					min = sequence[i];
				}
			}

			if (min == max) {

				// Change last element
				end = end - location;
			} else {
				for (i = start; i < end; ++i) {

					// Calculate slot

					slot = (int) Math.floor(((sequence[i] - min) / (double) (max - min)) * (location - 1));
					bucket.get(slot).add(sequence[i]);
				}
				for (i = 0; i < location; ++i) {
					if (bucket.get(i).isEmpty() == false) {

						// When bucket slot not empty
						// Assign the bucket element into actual array

						for (j = 0; j < bucket.get(i).size(); j++) {
							sequence[start] = bucket.get(i).get(j);
							start++;
						}

						// This is useful to trace the sort slot elements
						process.add(bucket.get(i).size());
					}
				}

				// Remove the existing bucket element
				for (i = 0; i < size; ++i) {
					bucket.get(i).clear();
				}
			}
		}
	}

	public static void main(String[] args) {

		// Define array of positive integer elements

		int[] s1 =  { 61, 53, 42, 14, 64, 2, -2, 6, 17, 9, 11, 3, 3, 4, 7};
		int[] s2 =  {16, 12, 6, 2, 8, 5, 9, 3, 5, 21, 22};

		// Test case A

		int size = s1.length;
		System.out.print("  Before Sort \n");
		display(s1, size);
		System.out.print("  After Sorted \n");
		interpolationSort(s1, size);
		display(s1, size);

		// Test case B

		size = s2.length;
		System.out.print("\n  Array \n");
		display(s2, size);
		interpolationSort(s2, size);
		System.out.print("  After Sorted \n");
		display(s2, size);
	}
}