/* FIFO */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front, *rear;
    int size;
} Queue;

void queue_destroy(Queue *);
Queue *queue_initialise();
void enqueue(Queue *, int, int);
Node *create_node(int, int);
void display(Queue *);
int dequeue(Queue *);

int main(int argc, char const *argv[])
{
    int choice;
    Queue *queue = queue_initialise();

    do
    {
        printf("\n\nMAIN MENU\n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nYour choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            int data, priority;
        case 1:
        {
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(queue, data, priority);
            display(queue);
            break;
        }
        case 2:
        {
            int ans = dequeue(queue);
            printf("Removed: %d\n", ans);
            display(queue);
            break;
        }
        case 3:
        {
            display(queue);
            break;
        }
        case 4:
        {
            queue_destroy(queue);
            return 0;
        }
        }

    } while (choice != 4);
    queue_destroy(queue);
    return 0;
}

void display(Queue *queue)
{
    Node *traverse = queue->front;
    while (traverse != NULL)
    {
        printf("%d->", traverse->data);
        traverse = traverse->next;
    }
    printf("NULL\n");
}

void enqueue(Queue *q, int data, int priority)
{
    Node *new_node = create_node(data, priority);
    if (q->front == NULL) //First element in the pqueue
    {
        q->front = new_node;
        q->rear = new_node;
        return;
    }

    Node *traverse = q->front, *insert_after = NULL;

    while (traverse->priority <= priority) //Untill we reach the relevant priority we use the traverse node
    {
        insert_after = traverse;
        traverse = traverse->next;
    }

    if (insert_after == NULL) //This says that the inputted number is lowest priority , (beginning)
    {
        new_node->next = q->front;
        q->front = new_node;
    }

    else //This means that the input is anywhere else but in the beginning of the queue , (anywhere)
    {
        new_node->next = insert_after->next;
        insert_after->next = new_node;
    }

    if (new_node->next == NULL) //This means that the inputted number is the highest priority, and is all the way in the end , (end)
    {
        q->rear = new_node;
    }
}

int dequeue(Queue *q)
{
    Node *to_del;
    int removed;

    if (q->front == NULL) //Empty list
        return -1;

    to_del = q->front; //Try and follow this method
    q->front = q->front->next;
    removed = to_del->data;
    free(to_del);
    return removed;
}

Node *create_node(int data, int priority)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->priority = priority;
    new_node->data = data;
    return new_node;
}

Queue *queue_initialise()
{
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

void queue_destroy(Queue *queue)
{
    if (queue == NULL)
        return;

    if (queue->front == NULL)
        return;

    Node *traverse = queue->front, *to_del = NULL;

    while (traverse->next != NULL)
    {
        to_del = traverse;
        traverse = traverse->next;
        free(to_del);
    }
    queue->front = NULL;
    queue->rear = NULL;
    free(queue);
}