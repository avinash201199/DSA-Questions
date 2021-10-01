package DSA.Week_3.Stringss;

import java.math.BigInteger;
import java.util.Scanner;

public class Multiply_two_strings {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            String a=sc.next();
            String b=sc.next();
            multiply g=new multiply();
            System.out.println(g.multiplyStrings(a,b));
        }
    }
}// } Driver Code Ends


//User function Template for Java

class multiply
{
    public String multiplyStrings(String s1,String s2)
    {
        //code here.

        return new java.math.BigInteger(s1).multiply(new java.math.BigInteger(s2)).toString();
    }
}
