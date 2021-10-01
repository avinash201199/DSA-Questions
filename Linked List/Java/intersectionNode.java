//Given the heads of two singly linked-lists headA and headB,
//return the node at which the two lists intersect. 
//If the two linked lists have no intersection at all, return null.
//For eg: listA = [1,9,1,2,4], listB = [3,2,4]
//output : Intersected at '2' .(we have to return the node)
//using hashSet we can add the elements of listA and then check if listB elements are
//present in the listB. If the elements the is present then return that node.
//else return null
//Definition for the linkedlist:
// * Definition for singly-linked list.
 /* public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
     }
  }
  */
public class Solution
{
   public ListNode getIntersectionNode(ListNode headA, ListNode headB)
   {
      HashSet<ListNode> visited = new HashSet<>();
      while(headA!=null)
      {
         visited.add(headA);
         headA = headA.next;
      }
     while(headB!=null)
     {
       if(visited.contains(headB))
       {
         return headB; 
       }
      headB = headB.next;
     }
     return null; 
   } 
}
//Time complexity: O(n) , Space : O(n).
