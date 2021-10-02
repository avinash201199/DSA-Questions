/*
Question: Merge two sorted linked lists and return it as a sorted list. 
Note: The list should be made by splicing together the nodes of the first two lists.
  
Example:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]


Structure of ListNode:
public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int value) { this.val = value; }
      ListNode(int value, ListNode next) { this.val = value; this.next = next; }
  }
*/

class Solution {
    public ListNode mergeTwoLinkedLists(ListNode head1, ListNode head2) {
        if(head1==null && head2==null) //if both lists are empty
            return null;
        else if(head1==null && head2!=null) //if 1st list is empty
            return head2;
        else if(head2==null && head1!=null) //if 2nd list is empty
            return head1;
        if(head1.val<=head2.val) //if value of node in 1st list is smaller than or equal to value of node in 2nd list
            head1.next = mergeTwoLinkedLists(head1.next,head2);
        else //if value of node in 1st list is greater than value of node in 2nd list
        {
            ListNode temp = head2;
            head2 = head2.next;
            temp.next = head1;
            head1 = temp;
            head1.next = mergeTwoLinkedLists(head1.next,head2);
        }
        return head1;
        
    }
}
