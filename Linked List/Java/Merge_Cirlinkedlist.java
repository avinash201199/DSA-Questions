import java.util.*;
class Merge_Cirlinkedlist
{
    Node head;
    public void add(Node node)
    {
        if (head == null)
        {
            head = node;
        }
        else
        {
            Node temp = head;
            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = node;
        }
    }
    void printList()
    {
        Node temp = head;
        while (temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        Merge_Cirlinkedlist llist1 = new Merge_Cirlinkedlist();
        Merge_Cirlinkedlist llist2 = new Merge_Cirlinkedlist();
        System.out.println("Enter 4 elements to be inserted in list 1 : ");   
        llist1.add(new Node(in.nextInt()));
        llist1.add(new Node(in.nextInt()));
        llist1.add(new Node(in.nextInt()));
        llist1.add(new Node(in.nextInt()));
        
        System.out.println("Enter 4 elements to be inserted in list 2 : ");
        llist2.add(new Node(in.nextInt()));
        llist2.add(new Node(in.nextInt()));
        llist2.add(new Node(in.nextInt()));
        llist1.add(new Node(in.nextInt()));
         
        System.out.println("Merged list: "); 
        llist1.head = Merge(llist1.head,llist2.head);
        llist1.printList();    
         
    }
    static Node Merge(Node headA, Node headB)
    {
        Node dummyNode = new Node(0);
        Node tail = dummyNode;
        tail.next = headB;
        while(true)
        {
            if(headA == null)
            {
                tail.next = headB;
                break;
            }
            if(headB == null)
            {
                tail.next = headA;
                break;
            }
            if(headA.data <= headB.data)
            {
                tail.next = headA;
                headA = headA.next;
            }
            else
            {
                tail.next = headB;
                headB = headB.next;
            }
            tail = tail.next;
        }
        return dummyNode.next;
    }
}
class Node
{
    int data;
    Node next;
    Node(int d) 
    {   data = d;
        next = null;
    }
}
