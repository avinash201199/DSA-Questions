//this programm is used for finding the cieling of a given number in an array;

public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 12, 34, 213, 232};
        System.out.println(cieling(arr, 234));
        
    }

    static int cieling(int[] arr, int target) {
        if(arr[arr.length-1]<target){return -1;}
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < arr[mid]) {
                end = mid - 1;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else return mid;
        }

        return start;
    }
}
