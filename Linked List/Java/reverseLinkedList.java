//Given the head of a singly linked list, reverse the list, and return the reversed list.
//for eg : [1,2,3,4,5]
//Output : [5,4,3,2,1]
//we use two pointers that are a newNode that keeps track of head.next
//and a prev node which keeps the track of the head while reversing
//defining the Linkedlist
/*
 public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
*/
public class Solution
{
  public LinkedNode reverseLinkedList(ListNode head)
  {
    ListNode prev = null;
    while(head!=null)
    {
      ListNode newNode = head.next;
      head.next = prev;
      prev = head;
      head = newNode;
    }
    return prev;
  }
}
//Time :O(n), space O(1)
