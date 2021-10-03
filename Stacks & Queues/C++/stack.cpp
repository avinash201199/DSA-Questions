#include<iostream>
using namespace std;
#define MAX 100

class stackArray
{
    public:
    int top;
    int arr[MAX];

    stackArray()
    {
        top=-1;
    }

    bool push(int x)
    {
        if (top>=MAX)
        {
            cout<<"Overflow"<<endl;
            return false;
        }
        top++;
        arr[top]=x;
        return true;
    }

    int pop()
    {
        if (top==-1)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else
        {
            int x=top;
            top--;
            return arr[x];
        }
    }

    int first()
    {
        if (top!=1)
        {
            return arr[top];
        }
        else
        {
            cout<<"The stack is empty"<<endl;
            return -1;
        }
        
    }
};

class linkedList
{
    public:
    int data;
    linkedList* next;
};

class stackLinkedList
{
    public:
    int top;
    linkedList* head;

    stackLinkedList()
    {
        head=NULL;
    }

    void push(int x)
    {
        linkedList* newNode = new linkedList();
        newNode->data=x;
        newNode->next=NULL;

        newNode->next=head;
        head=newNode;
    }

    int pop()
    {
        if (head!=NULL)
        {
            linkedList* deletedNode = head;
            delete deletedNode;
            int popval=head->data;
            head = head->next;
            return popval;
        }
        else
        {
            cout<<"The stack is empty"<<endl;
            return 0;
        }
        
        
    }

    int stackTop()
    {
        if (head!=NULL)
        {
            return head->data;
        }
        else
        {
            cout<<"The stack is empty"<<endl;
            return 0;
        }
        
    }

    void print()
    {
        linkedList* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


};

int main()
{
    class stackLinkedList s;

    s.push(1);
    s.push(2);
    s.print();
    cout<<s.pop()<<endl;
    cout<<s.stackTop()<<endl;
    s.push(3);
    s.push(6);
    s.print();
    cout<<s.pop()<<endl;
    cout<<s.stackTop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.print();
}