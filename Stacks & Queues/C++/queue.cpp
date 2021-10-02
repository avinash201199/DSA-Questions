#include<iostream>
using namespace std;
#define MAX 10

class queueArray
{
    public:
    int front,rear;
    int arr[MAX];

    queueArray()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        return (front==-1 && rear==-1);
    }

    bool isFull()
    {
        return (front==(rear+1)%MAX);
    }

    void Print()
    {
        if (isEmpty())
        {
            return;
        }
        
        for (int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    void enqueue(int n)
    {
        if (isEmpty())
        {
            front++;
            rear++;
        }
        else if (isFull())
        {
            return;
        }
        else
        {
            rear=(rear+1)%MAX;
        }   
        arr[rear]=n;

    }

    void deque()
    {
        if (isEmpty())
        {
            return;
        }
        else if(front==rear) 
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
        
    }
};

class node
{
    public:
    int data;
    node* next;
};

class queueLinkedList
{
    public:
    node *front,*rear;

    queueLinkedList()
    {
        front=NULL;
        rear=NULL;
    }

    bool isEmpty()
    {
        return !(front && rear);
    }    

    void enqueue(int n)
    {
        node* newNode = new node();
        newNode->data=n;
        newNode->next=NULL;
        if (isEmpty())
        {
            front=newNode;
            rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=rear->next;
        }    
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        else if (front==rear)
        {
            delete front;
            front=NULL;
            rear=NULL;
        }
        else
        {
            node* deleteNode=NULL;
            deleteNode=front;
            front=front->next;
            delete deleteNode;
        }
        
        
    }

    void Print()
    {
        node* temp=front;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<'\n';
    }
};

int main()
{
    class queueArray q;
    class queueLinkedList q1;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(4);
    // q.Print();
    // q.deque();
    // q.Print();
    // q.deque();
    // q.Print();
    // q.deque();
    // q.Print();
    // q.enqueue(5);
    // q.enqueue(6);
    // q.Print();

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.Print();
    q1.dequeue();
    q1.Print();
    q1.dequeue();
    q1.Print();
    q1.dequeue();
    q1.Print();
    q1.enqueue(5);
    q1.enqueue(6);
    q1.Print();
    
}