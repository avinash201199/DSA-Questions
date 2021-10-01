//A function that tells whether a linked list has a cycle or not.

//for eg1: [3,2,0,-4], pos = 1 
//output:true

//eg2: [1], pos=-1
//output=false

//Solution : Using 2 pointers
//time : O(n) , space: O(1)\
//Definition of data structure ListNode
/*class ListNode {
       int val;
       ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }*/
class Solution
{
  public boolean hasCycles(ListNode head)
  {
     if(head==null)
       return false;
    ListNode fast = head.next;
    ListNode slow = head;
    while(fast!=null && fast.next!=null && slow!=null)
    {
      if(fast==slow)
      {
        return true;
      }
      fast = fast.next.next;
      slow = slow.next;
    }
    return false;
  }
}
