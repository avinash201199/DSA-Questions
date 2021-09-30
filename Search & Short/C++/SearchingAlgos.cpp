#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> 

int BinarySearch(std::vector<int>& array, int l, int r, int number) {

	//recursive
	/*if (r >= l) {
		int mid = l + (r - l) / 2;

		if (array[mid] == number)
			return mid;

		if (array[mid] > number) {
			r = mid - 1;
			return BinarySearch(array, l, r, number);
		}

		if (array[mid] < number) {
			l = mid + 1;
			return BinarySearch(array, l, r, number);
		}

	} */

	//iterative
	int currNum = array[0];
	int mid;
	while (currNum != number) {
		if (r >= l) {
			mid = l + (r - l) / 2;

			if (array[mid] == number)
				return mid;

			if (array[mid] > number) {
				r = mid - 1;
			}

			if (array[mid] < number) {
				l = mid + 1;
			}
		}
		else
			return -1;
	}

	return mid;
}


int JumpSearch(std::vector<int>& numbers, int number) {
	int length = numbers.size();
	int jump = sqrt(length);
	int index1 = 0;
	int index2 = jump;
	int currNum = numbers[0];

	while (index2 < length) {
		if (numbers[index1] == number)
			return index1;

		if (numbers[index2] == number)
			return index2;

		if (numbers[index2] < number) {
			index1 += jump;
			index2 += jump;
			continue;
		}
		else if (numbers[index2] > number && numbers[index1] < number) {
			int found = -1;
			for (int i = index1; i <= index2; i++) {
				if (numbers[i] == number)
					return i;
			}
			return found;
		}
		else
			return -1;
	}


}


int InterpolationSearch(std::vector<int>& numbers, int number) {

	int high = numbers.size() - 1, low = 0, position;

	//pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]



	while (low <= high && number >= numbers[low] && number <= numbers[high]) {

		if (low == high) {
			if (numbers[low] == number)
				return low;
			return -1;
		}

		position = low + ((number - numbers[low]) * (double)(high - low) / (numbers[high] - numbers[low]));

		if (numbers[position] == number)
			return position;

		if (numbers[position] < number) {
			low = position + 1;
		}
		else {
			high = position - 1;
		}


	}

	return -1;

}

int ExponentialSearch(std::vector<int>& numbers, int number) {
	int vectorSize = numbers.size();
	if (numbers[0] == number)
		return 0;
	size_t i = 1;
	while (i < vectorSize && numbers[i] <= number) {
		i = i * 2;
	}

	int r = i / 2;
	int l = (int)fmin(i, vectorSize - 1);


	return BinarySearch(numbers, r, l, number);
}


int main() {

	std::vector<int> numbers;
	for (int i = 0; i < 100; i++)
		numbers.push_back(i);


	int r = numbers.size() - 1;
	int l = 0;

	int found = ExponentialSearch(numbers, 51205);

	if (found != -1)
		std::cout << "exists";
	else
		std::cout << "does not exist ";

	found = ExponentialSearch(numbers, 74);

	std::cout << std::endl;

	if (found != -1)
		std::cout << "exists";
	else
		std::cout << "does not exist ";



	return 0;
}