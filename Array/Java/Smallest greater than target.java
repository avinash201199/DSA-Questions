/* Find Smallest Letter Greater Than Target
     Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.
     Note that the letters wrap around
*/
public class Main {
    public static char nextGreatestLetter(char[] letters, char target) {
        int start=0;
        int end=letters.length-1;
        int mid=start+(end-start)/2;
        while(start <= end){
            mid=start+(end-start)/2;
            if(target < letters[mid])
                end=mid-1;
            else
                start=mid+1;

        }
        return letters[start%letters.length];
    }
    public static void main(String[] args) {
        char[] letters = {'c','f','j'};
        char target = 'p';
        System.out.println(nextGreatestLetter(letters,target));
    }
}