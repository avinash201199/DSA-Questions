///   BUBBLESORT METHOD   ///

import java.util.Scanner;

public class BubbleSort{

    public static void main(String[]args){

        Scanner sc=new Scanner(System.in);
        
        int n; 
        System.out.print("Enter the number of elements of the array: ");
        n=sc.nextInt();

        int[]a=new int[n];
        System.out.print("Enter the elements of the array: ");
        for(int i=0;i<a.length;i++) a[i]=sc.nextInt();

        boolean IsSorted=true;
        int aux;

        do{
            IsSorted=true;
            for(int i=0;i<a.length-1;i++)
            {
                if(a[i]>a[i+1])
                {
                    aux=a[i];
                    a[i]=a[i+1];
                    a[i+1]=aux;
                    IsSorted=false;
                }
                
            }

        }while(!IsSorted);
        
        System.out.print("The sorted array is: ");
        for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");
    }
} 