#include <stdio.h>
#define n 5
int stak[n];
int top=-1;

void push()
{
    int x;
    printf("Enter the number you wanna add: ");
    scanf("%d",&x);
    if (top==n-1)
       printf("Stack Overflow\n");
    else
    {
        top++;
        stak[top]=x;
        printf("Succesfully Inserted !!\n");
    }
}

void pop()
{
    int data;
    if (top==-1)
        printf("Stack Underflow\n");

    else
    {
        data=stak[top];
        top--;
        printf("Removed %d from the stack\n",data);
        
    }
}

void peep()
{
    int p;
    printf("Wanna see which index: ");
    scanf("%d",&p);
    if (top+1-p<=0)
        printf("Stack Underflow\n");

    else
        printf("%d",stak[top-p+1]);

}

void display()
{
    int i;
    printf("Elements available in the stack are:");
    for (i=top;i>=0;i--)
    {
        printf("%d\t",stak[i]);
    }
    printf("\n");
}

void change()
{
    int p,el,el2;
    printf("Wanna change element which index: ");
    scanf("%d",&p);
    printf("Enter the element: ");
    scanf("%d",&el2);
    if (top+1-p<=0)
        printf("Stack Underflow\n");
    else
    {   el=stak[top-p+1];
        stak[top-p+1]=el2;
        printf("Sucessfully changed %d with %d at index %d",el,el2,p); 
        printf("\n");
        display();
    }
}


void main()
{
  while(1)
  {
    int a;
    printf("\n1.Insert an element \n2.Delete an element \n3.Peep an element \n4.Display Stack  \n5.Change an element \n6.Exit");
    printf("\nEnter your Choice: ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            change();
            break;
        case 6:
            goto end;
            
        default:
            printf("You have Entered a wrong input !");
        
    }
  }      
    end:
    printf("Out of the Loop!!");
}


