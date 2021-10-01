//Time Complexity - O(n^2)
//Space Complexity - O(1)

const swap = (arr, idx1, idx2) => {
  let temp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;
};

const selectionSort = (arr) => {
  if (arr.length <= 1) return arr;
  let leastNumIndex;
  for (let i = 0; i < arr.length; i++) {
    leastNumIndex = i;
    for (j = i; j < arr.length; j++) {
      if (arr[j] < arr[leastNumIndex]) {
        leastNumIndex = j;
      }
    }
    swap(arr, leastNumIndex, i);
  }
  return arr;
};

const array = [
  100,
  56,
  34,
  224,
  45,
  453,
  232,
  4,
  53,
  3,
  2,
  15,
  35,
  34,
  4,
  7,
  -1,
  -5,
  -20,
  49,
];

console.log(selectionSort(array));
