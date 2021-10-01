/*
 * C++ Program to Implement Stack using Two Queues
 */
#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct queue1
{
    queue1 *next1;
    int data1;
}*front1 = NULL, *rear1 = NULL, *q1 = NULL, *p1 = NULL, *np1 = NULL;
struct queue2
{
    queue2 *next2;
    int data2;
}*front2 = NULL, *rear2 = NULL, *q2 = NULL, *p2 = NULL, *np2 = NULL;
void enqueue1(int x)
{     
    np1 = new queue1;
    np1->data1 = x;
    np1->next1 = NULL;
    if (front1 == NULL)
    {
        rear1 = np1;
        rear1->next1 = NULL;
        front1 = rear1;
    }
    else
    {
        rear1->next1 = np1;
        rear1 = np1;
        rear1->next1 = NULL;
    }
}
int dequeue1()
{
    int x;
    if (front1 == NULL)
    {
        cout<<"no elements present in queue\n";
    }
    else
    {
        q1 = front1;
        front1 = front1->next1;
        x = q1->data1;
        delete(q1);
        return x;
    }
}
void enqueue2(int x)
{
    np2 = new queue2;
    np2->data2 = x;
    np2->next2 = NULL;
    if (front2 == NULL)
    {
        rear2 = np2;
        rear2->next2 = NULL;
        front2=rear2;
    }
    else
    {
        rear2->next2 = np2;
        rear2 = np2;
        rear2->next2 = NULL;
    }
}
int dequeue2()
{
    int x;
    if (front2 == NULL)
    {
        cout<<"no elements present in queue\n";
    }
    else
    {
        q2 = front2;
        front2 = front2->next2;
        x = q2->data2;
        delete(q2);
        return x;
    }
}        
int main()
{
    int n, x, i = 0;
    cout<<"Enter the number of elements to be entered into stack\n";
    cin>>n;
    while (i < n)
    {
        cout<<"enter the element to be entered\n";
        cin>>x;
        enqueue1(x);
        i++;
    }
    cout<<"\n\nElements popped\n\n";
    while (front1 != NULL || front2 != NULL)
    {
        if (front2 == NULL)
        {
            while (front1->next1 != NULL)
            {
                enqueue2(dequeue1());
            }
            cout<<dequeue1()<<endl;
        }
        else if (front1 == NULL)
        {
            while (front2->next2 != NULL)
            {
                enqueue1(dequeue2());
            }
            cout<<dequeue2()<<endl;
        }
    }
    getch();
}


/*      OUTPUT
Output
 
Enter the number of elements to be entered into stack
7
enter the element to be entered
3
enter the element to be entered
9
enter the element to be entered
1
enter the element to be entered
0
enter the element to be entered
6
enter the element to be entered
4
enter the element to be entered
2
 
 
Elements popped
 
2
4
6
0
1
9
3
*/