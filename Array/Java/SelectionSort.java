import java.util.*;

public class SelectionSort {  
    public static void SelectionSort(int[] arr)
    {  
        for (int i = 0; i < arr.length - 1; i++)  
        {  
            int index = i;  
            for (int j = i + 1; j < arr.length; j++)
            {  
                if (arr[j] < arr[index])
                {  
                    index = j;  
                }  
            }  
            int num = arr[index];   
            arr[index] = arr[i];  
            arr[i] = num;  
        }  
    }  
       
    public static void main(String args[]){  
        int[] array1 = {87,9,45,52,14,3,11,63};  
        System.out.println("Before Selection Sort the array is");  
        for(int i : array1)
        {  
            System.out.print(i+" ");  
        }  
        System.out.println();  
          
        SelectionSort(array1);
         
        System.out.println("After Selection Sort the array is");  
        for(int i : array1)
        {  
            System.out.print(i+" ");  
        }  
    }  
}  
