import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args) {
        int[] arr = {4,5,2,1,3};
        System.out.println("Array before sorting :");
        System.out.println(Arrays.toString(arr));
        cyclicSort(arr);
        System.out.println("Array after sorting :");
        System.out.println(Arrays.toString(arr));



    }
    static void swap(int[] arr,int first,int second){
        int temp =  arr[first];
        arr[first] = arr[second];
        arr[second] = temp;

    }


    static void cyclicSort(int[] nums){
        int i =0;
        while(i < nums.length){
            int correct = nums[i] - 1;
            if(nums[i] != nums[correct]){
                swap(nums,i,correct);
            }else{
                i++;
            }
        }
    }
}
