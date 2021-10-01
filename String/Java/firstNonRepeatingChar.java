import java.util.*;

public class firstNonRepeatingChar {
    public static int firstUniqChar(String s) {
        HashMap<Character, Integer> m = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            // getdefault is used for setting a default value in
            m.put(s.charAt(i), m.getOrDefault(s.charAt(i), 0) + 1);
        }
        for (int i = 0; i < s.length(); i++) {
            if (m.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.print(firstUniqChar(s));

    }
}
