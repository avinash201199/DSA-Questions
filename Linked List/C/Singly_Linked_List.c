//Kumar Ankit
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure of a node in Linked List
struct node{
    int data;
    struct node *next;
};

//Creating function of Linked List
void create(struct node **h, int n){
    struct node *curr, *ptr;
    printf("Entries: ");
    for(int i=0;i<n;i++){
        curr = (struct node *)malloc(sizeof(struct node)); //dynamically allocating memory to a node
        scanf("%d", &curr->data);
        curr->next = NULL;
        if(*h==NULL){
            *h = curr;
            ptr = curr;
        }else{
            ptr->next = curr;
            ptr = curr;
        }
    }
}

//Displaying the Linked List
void display(struct node *h){
    struct node *curr;
    for(curr=h; curr!=NULL; curr=curr->next){
        printf("%d ", curr->data);
    }
    printf("\n");
}

//Inserting into Linked List
void insert(struct node **h, int v, int pos){
    struct node *curr;
    curr = (struct node *)malloc(sizeof(struct node)); //dynamically allocating memory to a new node
    curr->data = v;
    curr->next = NULL;
    if(*h == NULL){ //if list is empty
        *h == curr;
    }else if(pos==0){ //if node is to be inserted at the starting
        curr->next = *h;
        *h = curr;
    }else{ //anywhere else the node is to be inserted
        struct node *ptr = *h;
        int i=1;
        while(i<pos && ptr->next!=NULL){
            ptr=ptr->next;
            i++;
        }
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

//Deleting a node in Linked List
void delete(struct node **h, int p){
    struct node *ptr, *prev;
    if(*h == NULL){ //if list is empty
        printf("EMPTY\n");
    }else{
        ptr = *h;
        int i = 1;
        while(i<p && ptr!=NULL){ //move to the previous position of the node to be deleted
            prev = ptr;
            ptr = ptr->next;
            i++;
        }
        if(ptr == NULL){ //if position given is not present in list
            printf("Node not present\n");
        }else if(ptr == *h){ //Alternative: else if(pos == 1), deleting the first element
            *h == ptr->next;
            free(ptr);
        }else{ //deleting any other element
            prev->next = ptr->next;
            free(ptr);
        }
    }
}

//Searching in Linked List
void search(struct node *h, int v){
    struct node *ptr;
    bool ch = false;
    for(ptr = h; ptr!=NULL; ptr = ptr->next){
        if(ptr->data == v){
            printf("Found\n");
            ch = true;
            break;
        }
    }
    if(ch == false){
        printf("Not Found\n");
    }
}

//Displaying Linked List using Recursion
void display_through_recursion(struct node *h){
    if(h == NULL) return;
    printf("%d ", h->data);
    display_through_recursion(h->next);
}

int main(){
    struct node *head1 = NULL;
    int n;
    printf("Enter number of initial entries : ");
    scanf("%d", &n);
    create(&head1, n);
    display(head1);
    display_through_recursion(head1);
    printf("\n");
    insert(&head1, 15, 3);
    display(head1);
    delete(&head1, 3);
    display_through_recursion(head1);
    printf("\n");
    search(head1, 3);
    return 0;
}