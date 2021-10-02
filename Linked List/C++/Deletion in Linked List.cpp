//Program for Deleting Node in Linked list
#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
class Node
{
    public :
    int data ;
    Node* next ;
    Node(int data)
    {
        this->data = data ;
        this->next = NULL;
    }
};
Node* takeInput()
{
    int data ;
    //Node* x = NULL ;
    cin>>data ;
    Node* head = new Node(data) ;
    Node* x = head ;
    cin>>data ;
    while(data != -1)
    {
        Node* temp = new Node(data) ;
        x->next = temp ;
        x = temp ;
        cin>>data;
    }
    return head ;
}
void print(Node* head)
{
    Node* temp = head ;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
}
Node* delete_Node(Node* head, int pos)
{
    Node* temp = head ;
    if(pos == 0)
    {
        head = head->next ;
        delete temp ;
        return head ;
    }
    for(int i=0;i<pos-1;i++)
    {
        temp = temp->next ;
    }
    if(temp->next == NULL)
        return head ;
    Node* x = temp->next ;
    temp->next = x->next ;
    delete x ;
    return head ;
}
int main()
{
    cout<<"Instructions :- "<<endl;
    cout<<"Keep Entering values in Linked List separated by space."<<endl;
    cout<<"Give value -1 when you want to terminate your Linked List."<<endl;
    cout<<endl;
    cout<<"Enter Linked List:";
    Node* head = takeInput() ;
    cout<<"Your Linked List is :- "<<endl ;
    print(head);
    cout<<endl<<endl;
    int pos ;
    cout<<"Enter position of Node which you want to delete: ";
    cin>>pos ;
    head = delete_Node(head,pos);
    cout<<endl;
    cout<<"Linked List after deletion is :- "<<endl ;
    print(head);
    return 0 ;
}
