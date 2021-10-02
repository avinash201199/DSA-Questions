#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

//head for the first node of Linked List(LL) and temp is for traversing the LL.
struct node *head = NULL;
struct node *temp = NULL;

/* function to create nodes and 
   link it to the end of Linked List(LL) */
void create(){
    int element;
    //we are making a new node, i.e., pointer to struct node
    struct node *nn;
    //dynamic memory allocation of size of a struct node
    nn = (struct node*)malloc(sizeof(struct node));
    
    scanf("%d",&element);
    nn->data = element;  //we are assigning value of input to the data of nn
    nn->next = NULL;
    
    if(head == NULL){    //if we are adding the first node of LL, head would be NULL
        head = nn;
        temp = nn;
    }
    
    else{                //we are adding nn to the end of LL and traversing temp to nn.
        temp->next = nn;
        temp = temp->next;
    }
}

/* function to insert nodes at 
   specific index of LL */
void insert(int *size){
    int nElement, post, i;
    
    struct node *temp1;
    temp1 = head;
    
    //taking input for node value and position to insert the node in LL 
    printf("Enter a node and post to insert\n");
    scanf("%d%d",&post, &nElement);
    
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = nElement;
    nn->next = NULL;
    
    /*if position is out of range of LL
      which is, position is more than last_index+1 of LL*/
    if(post>*size+1) return;
    
    //if nn is to be inserted as first node of LL
    else if(post == 1){
        nn->next = head;
        head = nn;
        *size = *size+1;
    }
    
    else{
        //we are traversing temp1 to pos-1 location in the LL
        for(i=0;i<post-2;i++){
            temp1 = temp1->next;
        }
        //we are changing the connections to add nn at the requested position
        nn->next = temp1->next;
        temp1->next = nn;
        *size = *size+1;
    }
    
    //we are calling the function to display the linked list
    displayList();
}

/* function to delete nodes at 
   specific index of LL */
void delete(int *size){
    int nElement, i;
    
    struct node *temp1, *temp2;
    temp1 = head;
    
    printf("Enter a element to delete\n");
    scanf("%d", &nElement);
    
    //if the node to be deleted is head of LL
    if(nElement == temp1->data){
        head  = temp1->next;
        free(temp1);
        displayList();
    } 
    
    else {
        while(temp1!=NULL){
            //temp2 is always next of temp1
            temp2 = temp1->next;
            
            /* if temp2 is NULL, it means the traversing process has 
               reached the end of LL and the element is not found */
            if(temp2 == NULL){
                displayList();
                printf("element %d is not found\n",nElement);
                break;
            }
            
            /* if temp2 is equal to the node we requested to delete, 
               we are changing the links of the nodes and 
               freeing the node to be deleting from the memory */
            else if(temp2->data == nElement){
                temp1->next = temp2->next;
                free(temp2);
                *size = *size -1;  // we are decreasing the size of the node by 1
                displayList();
                break;
            }
            
            //we are shifting temp1 to next node
            temp1 = temp1->next;
        }
    }
}

void search(int *size){
    int i, element, test=0;
    
    struct node *temp;
    temp = head;
    
    printf("enter element to search\n");
    scanf("%d",&element);
    
    // we are traversing LL using temp node 
    while(temp!=NULL){
        // if the element is found, we are assigning test = 1, and breaking the loop
        if(temp->data == element){
            test = 1;
            break;
        }
        temp = temp->next;
    }
    
    if(test == 0) printf("not found\n");
    else printf("found\n");
}


void displayList(){
    struct node *display;
    display = head;
    //we are traversing the list using display node and printing the data of the node
    while(display != NULL){
        printf("%d->",display->data);
        display = display->next;
    }
    printf("NULL\n");
}


int main(){
    int size, i;
    
    printf("Enter the number of nodes to form linked list : ");
    scanf("%d",&size);
    
    printf("Enter the nodes\n");
    for(i=0;i<size;i++){
        create();
    }
    
    //we are taking input of option from the user to perform their required operation
    while(1){
        int option;
        
        printf("Choose the option\n1.insert a node\n2.delete a node\n3.search a node \n4.exit\n");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                insert(&size);
                break;
            case 2:
                delete(&size);
                break;
            case 3:
                search(&size);
                break;
            case 4:
                printf("Thank You!");
                exit(1);
        }
    }
    
}