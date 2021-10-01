package main

import "fmt"

func bubbleSort(arr []int) []int {
	for i := range arr {
		for j := i + 1; j < len(arr); j++ {
			if arr[i] > arr[j] {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}
	}

	return arr
}

func main() {
	fmt.Println(bubbleSort([]int{3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48}))
}
