//It is a Linear Search Algorithm;
//the Complexity of this Algorithm is O(n)


public class LinearSearch {
    public static void main(String[] args) {
        int[]arr={2,34,45,123,452,12};
        System.out.println(  lsearch(arr ,5));
    }

     static int lsearch(int[] arr, int num) {
        int temp=num;
        int i=0;
        while(i< arr.length){
            if(temp==arr[i]){
                System.out.println("element found");
            }

            i++;
            return i;
        }
return -1;
}
}
