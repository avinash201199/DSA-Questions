import java.util.*;

class BinarySearch{  
 public static void BinarySearch(int arr[], int first, int last, int key)
 {  
   int mid = (first + last)/2;  
   while( first <= last ){  
      if ( arr[mid] < key )
      {  
        first = mid + 1;     
      }
     else if ( arr[mid] == key )
      {  
        System.out.println("Element found at index: " + mid);  
        break;  
      }
     else
     {  
         last = mid - 1;  
      }  
      mid = (first + last)/2;  
   }  
   if ( first > last )
   {  
      System.out.println("Element not found!");  
   }  
 }  
  
 public static void main(String args[])
 {  
        int arr1[] = {6,20,27,33,54};  
        int key = 33;  
        int l = arr1.length-1;  
        BinarySearch(arr1,0,l,key);     
 }  
}  
