/* 
Given a string and a pattern, print all the occurrences of the pattern in the string

Input:

String: abxabcabcabyxxyabcaby
Pattern: abcaby

Output:

Found pattern at index 6
Found pattern at index 15

Explanation: The pattern starts at indices 6 and 15 in the string (using 0-indexing format)
*/

import java.util.*;

public class KMPStringMatching {
    static int[] lps(String s) {
        int n = s.length();
        int prefix[] = new int[n];
        prefix[0] = 0;
        int i = 0, j = 1;
        while (i < n && j < n) {
            if (s.charAt(i) == s.charAt(j)) {
                prefix[j++] = (i++ + 1);
            } else {
                if (i > 0)
                    i = prefix[i - 1];
                else
                    j++;
            }
        }
        return prefix;
    }

    static void matchString(String word, String pat) {
        int m = word.length();
        int n = pat.length();
        int lps[] = lps(pat);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (word.charAt(i) == pat.charAt(j)) {
                i++;
                j++;
            }
            if (j == n) {
                System.out.println("Found pattern " + "at index " + (i - j));
                j = lps[j - 1];
            } else if (i < m && word.charAt(i) != pat.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else
                    i++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine(); // String
        String pat = sc.nextLine(); // Pattern
        matchString(str, pat);
        sc.close();
    }
}