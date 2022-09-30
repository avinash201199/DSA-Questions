
/*Given a string str, write code to find the length of the longest substring without repeating characters.


Example 1:

Input: str = " "
Output: 1
Explanation: The answer is " " (i.e. space), so the length is 1.

Example 2:

Input: str = ""
Output: 0
Explanation: The string is empty, so the length is 0.

Example 3:

Input: str = "xyzxybbc"
Output: 4
Explanation: The answer is "zxyb", with the length of 4.

Example 4:

Input: str = "ccccc"
Output: 1
Explanation: The answer is "c", with the length of 1.
Example 3:

*/




public class LongestSubStr {

public static int lengthOfLongestSubstring(String str) {

		int maxCount = 0;
		if (str.length() == 1)
			return 1;

		for (int i = 0; i < str.length(); i++) {
			int counter = 1;
			String subStr = str.charAt(i) + "";
			for (int j = i + 1; j < str.length(); j++) {
				if (subStr.contains(str.charAt(j) + "")) {
					break;
				} else {
					counter++;
					subStr += str.charAt(j) + "";
				}
			}
			if (maxCount < counter)
				maxCount = counter;
		}

		return maxCount;
	}

	public static void main(String[] args) {

		System.out.println(LongestSubStr.lengthOfLongestSubstring(" "));
		System.out.println(LongestSubStr.lengthOfLongestSubstring(""));

		System.out.println(LongestSubStr.lengthOfLongestSubstring("xyzxybbc"));
		System.out.println(LongestSubStr.lengthOfLongestSubstring("ccccc"));


	}
