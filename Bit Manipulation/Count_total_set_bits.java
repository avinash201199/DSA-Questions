package DSA.Week_3.BITs;

import java.io.IOException;
import java.util.Scanner;

public class Count_total_set_bits {
    public static void main(String[] args) throws NumberFormatException, IOException {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();//testcases
        int x, n;
        while(t-->0) {
            n = sc.nextInt();//input n

            Solution obj = new Solution();

            System.out.println(obj.countSetBits(n));//calling countSetBits() method
        }
    }
}
class Solution{

    //Function to return sum of count of set bits in the integers from 1 to n.
    public static int countSetBits(int n){

        // Your code here
if(n==0){
    return 0;
}
        int x=power(n);
        int a=x*(1<<(x-1));
        int b=(n-(1<<x)+1);
        int rest=n-(1<<x);
        int count=a+b+countSetBits(rest);
        return count;
    }
    public static int  power(int n){

        int x=0;
        while ((1<<x)<=n){
            x++;
        }
        return x-1;
    }

}