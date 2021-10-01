#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

typedef struct list {
    Node* head;
    int no_of_elements;
} List;

List* init_list();
void display(List*);
void destroy_list(List*);
void insert_front(List*, int);
void insert_end(List*, int);
void insert_pos(List*, int, int);
void delete_front(List*);
void delete_end(List*);
void delete_pos(List*, int);
void delete_val(List*, int);

int main() {
    List *list = NULL;

    list = init_list();
    

    int ch;
    int data;

    while (1) {
        printf("\n\nMAIN MENU\n\n");
        printf("1. Insert element to front\n");
        printf("2. Insert element to end\n");
        printf("3. Insert into any position\n");   
        printf("4. Delete element at front\n");
        printf("5. Delete element at end\n");
        printf("6. Delete element from any position\n"); 
        printf("7. Delete first occurance of value\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("\nYour choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                // Front insert
                printf("Enter number: ");
                scanf("%d", &data);
                insert_front(list, data);
                display(list);
                break;
            }
            case 2: {
                // End insert
                printf("Enter number: ");
                scanf("%d", &data);
                insert_end(list, data);
                display(list);
                break;
            }
            case 3: {
                // Insert pos
                int pos, val;
                printf("Enter position (1-based index): ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                insert_pos(list, pos, val);
                display(list);
                break;
            }
            case 4: {
                // Delete front
                delete_front(list);
                display(list);
                break;
            }
            case 5: {
                // Delete end
                delete_end(list);
                display(list);
                break;
            }
            case 6: {
                // Delete pos
                int pos;
                printf("Enter position (1-based index): ");
                scanf("%d", &pos);
                delete_pos(list, pos);
                display(list);
                break;
            }
            case 7: {
                // Delete val
                int val;
                printf("Enter value: ");
                scanf("%d", &val);
                delete_val(list, val);
                display(list);
                break;
            }
            case 8: {
                // Display
                display(list);
                break;
            }
            case 9: {
                // Exit
                destroy_list(list);
                return 0;
            }
            default: {
                printf("Invalid input\n");
                continue;
            }
        }
    }
    destroy_list(list);
    return 0;
}

List* init_list() {
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->no_of_elements = 0;
    return list;
}

void destroy_list(List *list) {
    Node *temp = list->head, *to_delete = NULL;

    while (temp != NULL) {
        if (to_delete != NULL) {
            free(to_delete);
        } 
        to_delete = temp;
        temp = temp->next;
        
    }

    if (list != NULL) {
        free(list);
    }

}

void insert_front(List *list, int val) {
    Node *traverse = list->head;
    Node* new_node = NULL;

    new_node = (Node*) malloc(sizeof(Node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = traverse;
    ++list->no_of_elements;
    
    // If not first node
    if (traverse != NULL) {
        traverse->prev = new_node;
    }
    
    list->head = new_node;
    
}

void insert_end(List *list, int val) {
    Node *traverse = list->head;
    Node* new_node = NULL;

    ++list->no_of_elements;

    // First node
    if (traverse == NULL) {
        new_node = (Node*) malloc(sizeof(Node));
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = traverse;
        list->head = new_node;
        return;
    }

    while (traverse->next != NULL) {
        traverse = traverse->next;
    }

    new_node = (Node*) malloc(sizeof(Node));
    traverse->next = new_node;
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = traverse;
}   

void insert_pos(List *list, int pos, int val) {
    Node *traverse = list->head;
    Node* new_node = NULL;

    // List is empty
    if (traverse == NULL) {
        new_node = (Node*) malloc(sizeof(Node));
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;
        list->head = new_node;
        ++list->no_of_elements;
        return;
    }
    int counter = 1;

    while (traverse != NULL) {
        // Position found, insert after
        if (pos == counter) {
            new_node = (Node*) malloc(sizeof(Node));
            new_node->data = val;

            // Set next and next's prev
            new_node->next = traverse->next;
            if (traverse->next != NULL) {
                (traverse->next)->prev = new_node;
            }
            
            // Set prev and prev's next
            traverse->next = new_node;
            new_node->prev = traverse;
            ++list->no_of_elements;
            return;

        }
        traverse = traverse->next;
        ++counter;
    }
}

void delete_front(List *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    list->head->next->prev = NULL;
    list->head = list->head->next;
    free(temp);
    --list->no_of_elements;
}

void delete_end(List *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *traverse = list->head;
    Node *to_del = NULL;

    if (list->head->next == NULL) {
        to_del = list->head;
        list->head = NULL;
        free(to_del);
        --list->no_of_elements;
        return;
    }

    while (traverse->next != NULL) {
        traverse = traverse->next;
    }


    to_del = traverse;
    traverse->prev->next = NULL;
    free(to_del);
    --list->no_of_elements;

}

void delete_pos(List *list, int pos) {
    // List is empty
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *traverse = list->head;
    Node* to_del = NULL;

    int counter = 1;

    while (traverse != NULL) {
        // Position found, value
        if (pos == counter) {
            to_del = traverse;

            // If not first node
            if (traverse->prev != NULL) {
                traverse->prev->next = traverse->next;
            }
            // First node
            else {
                list->head = list->head->next;
            }
            // If not last node
            if (traverse->next != NULL) {
                traverse->next->prev = traverse->prev;
            }
            
            free(to_del);
            --list->no_of_elements;
            return;

        }
        traverse = traverse->next;
        ++counter;
    }
}

void delete_val(List *list, int val) {
    // List is empty
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *traverse = list->head;
    Node* to_del = NULL;


    while (traverse != NULL) {
        // Value found, delete
        if (val == traverse->data) {
            to_del = traverse;

            // If not first node
            if (traverse->prev != NULL) {
                traverse->prev->next = traverse->next;
            }
            // First node
            else {
                list->head = list->head->next;
            }
            // If not last node
            if (traverse->next != NULL) {
                traverse->next->prev = traverse->prev;
            }
            
            free(to_del);
            --list->no_of_elements;
            return;

        }
        traverse = traverse->next;
    }
}

void display(List *list) {
    Node *traverse = list->head;

    while (traverse != NULL) {
        printf("%d->", traverse->data);
        traverse = traverse->next;
    }
    printf("NULL\n");
}