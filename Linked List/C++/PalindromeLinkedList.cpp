
/*Palindrome Linked List:

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.*/

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL){
        return true;
    }
    int count = 0;
    Node *temp = head;
    while(temp!=NULL){
        count = count+1;
        temp = temp->next;
    }
    if(count==1){
        return true;
    }
    Node *temp2 = head;
    int count1 = 1;
    int count2 = 1;
    if(count%2==0){
        while(count1<count/2){
            temp2 = temp2->next;
            count1++;
        }
        Node *temp3 = temp2->next;
        temp2->next = NULL;
        Node *t1 = temp3;
        Node *t2 = temp3->next;
        Node *t3 = temp3;
        Node *t4 = NULL;
        while(t2->next!=NULL){
            t4 = t2->next;
            t2->next = t3;
            t3 = t2;
            t1 = t2;
            t2 = t4;
        }
        t2->next = t3;
        temp3->next = NULL;
        temp3 = t2;
        Node *ptr1 = temp3;
        Node *ptr2 = head;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->data!=ptr2->data){
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }else{
        while(count2<count/2){
            temp2 = temp2->next;
            count2++;
        }
        Node *temp3 = temp2->next;
        temp2->next = NULL;
        Node *t1 = temp3;
        Node *t2 = temp3->next;
        Node *t3 = temp3;
        Node *t4 = NULL;
        while(t2->next!=NULL){
            t4 = t2->next;
            t2->next = t3;
            t3 = t2;
            t1 = t2;
            t2 = t4;
        }
        t2->next = t3;
        temp3->next = NULL;
        temp3 = t2;
        Node *ptr1 = temp3;
        Node *ptr2 = head;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->data!=ptr2->data){
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
    
    
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}