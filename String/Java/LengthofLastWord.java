/**
Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
 */


import java.util.*;
class LengthofLastWord 
{
    static int lengthOfLastWord(String s) {
        int count = 0;
        if(s==null || s==" ")
            return 0;
        else
        {
            s=s.trim();
            for(int i=s.length()-1; i>-1; i--)
                if(s.charAt(i) == ' ')
                    break;    
                else
                    count++;
        }
        return count;
    }
    public static void main(String[] args)  
    {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        System.out.println("Length of last word of given String is : "+ lengthOfLastWord(s));   
    }
}