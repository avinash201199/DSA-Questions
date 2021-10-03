#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    struct Node* result = NULL;
 
    
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2) {
        push(&a, keys[i]);
    }
 
    for (int i = n - 2; i >= 0; i = i - 2) {
        push(&b, keys[i]);
    }
 
    printf("First List: ");
    printList(a);
 
    printf("Second List: ");
    printList(b);
 
    struct Node* head = sortedMerge(a, b);
    printf("After Merge: ");
    printList(head);
 
    return 0;
}


