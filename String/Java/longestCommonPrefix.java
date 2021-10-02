import java.util.Scanner;

public class longestCommonPrefix {
    public static String longest_Common_Prefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i == strs[j].length() || strs[j].charAt(i) != ch)
                    return strs[0].substring(0, i);
            }

        }
        return strs[0];

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        String arr[] = new String[n];
        System.out.print("Enter the elements of the array: ");
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.next();
        System.out.println("The longest common prefix is: " + longest_Common_Prefix(arr));

    }
}
// Input: strs = ["flower","flow","flight"]
// Output: "fl"