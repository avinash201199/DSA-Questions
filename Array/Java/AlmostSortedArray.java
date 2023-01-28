/*

By- Krish Jani (KrishJani)

Question: Given an array that is sorted such that some 
elements are moved to either of the adjacent positions, 
i.e., A[i] may be present at A[i+1] or A[i-1]. Write an 
efficient function to search an element in this array. 
Basically, the element A[i] can only be swapped with 
either A[i+1] or A[i-1].

Approach: Compare the key with middle 3 elements, if 
present then return the index. If not present, then 
compare the key with middle element to decide whether 
to go in left half or right half. Comparing with middle 
element is enough as all the elements after mid+2 must be 
greater than element mid and all elements before mid-2 must 
be smaller than mid element.

*/



 class HacktoberFest
{
    int binarySearch(int A[], int l, int r, int x)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;
 
            if (A[mid] == x)
                return mid;
            if (mid > l && A[mid - 1] == x)
                return (mid - 1);
            if (mid < r && A[mid + 1] == x)
                return (mid + 1);
 
            if (A[mid] > x)
                return binarySearch(A, l, r, x);
 
            return binarySearch(A, mid + 2, r, x);
        }
 
        
        return -1;
    }
 
    
    public static void main(String args[])
    {
        HacktoberFest ob = new HacktoberFest();
        int A[] = {31, 21, 101, 41, 401};
        int n = A.length;
        int x = 4;
        int result = ob.binarySearch(A, 0, n - 1, x);
        if(result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element present at index " +
                                result);
    }
}