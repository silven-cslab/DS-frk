/** ===== Experiment 1: Singly Linked List (Insertion and Deletion) ===== **/

/** ===== Documentation ===== **/
/*
 * This program implements insertion and deletion operations on a singly linked list.
 * Operations available:
 *  1. Insert at front, position, and end.
 *  2. Delete from front, position, and end.
 *  3. Display current list.
 */

/** ===== Preprocessing Directives ===== **/
#include<stdio.h>      // For printf(), scanf().
#include<stdlib.h>     // For malloc(), free().

/** ===== Global Declarations ===== **/
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void appendNode(int value);
int displayList(void);
int listLength(void);
int insertFront(int value);
int insertAtPosition(int value, int position);
int insertEnd(int value);
int deleteFront(void);
int deleteAtPosition(int position);
int deleteEnd(void);
void freeList(void);

/** ===== Main Function ===== **/
int main(void)
{
    int choice, value, position, n, status = 0;

    printf("\n===== Experiment 1: Singly Linked List =====\n");
    printf("Enter initial number of nodes: ");
    if(scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    if(n > 0)
    {
        printf("Enter %d node values: ", n);
        for(int i = 0; i < n; i++)
        {
            if(scanf("%d", &value) != 1)
            {
                printf("Invalid input.\n");
                freeList();
                return 1;
            }
            appendNode(value);
        }
    }

    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Display List\n");
        printf("2. Insert Front\n");
        printf("3. Insert Position\n");
        printf("4. Insert End\n");
        printf("5. Delete Front\n");
        printf("6. Delete Position\n");
        printf("7. Delete End\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid choice input.\n");
            status = 1;
            break;
        }

        switch(choice)
        {
            case 1:
                displayList();
                break;
            case 2:
                printf("Enter value to insert at front: ");
                if(scanf("%d", &value) != 1 || insertFront(value)) status = 1;
                break;
            case 3:
                printf("Enter value and position (1-based): ");
                if(scanf("%d %d", &value, &position) != 2 || insertAtPosition(value, position))
                {
                    status = 1;
                }
                break;
            case 4:
                printf("Enter value to insert at end: ");
                if(scanf("%d", &value) != 1 || insertEnd(value)) status = 1;
                break;
            case 5:
                if(deleteFront()) status = 1;
                break;
            case 6:
                printf("Enter position to delete (1-based): ");
                if(scanf("%d", &position) != 1 || deleteAtPosition(position)) status = 1;
                break;
            case 7:
                if(deleteEnd()) status = 1;
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
                status = 1;
        }
    } while(choice != 8);

    freeList();
    return status;
}

/** ===== Function Definitions ===== **/

struct node* createNode(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(int value)
{
    struct node *newNode = createNode(value);
    if(newNode == NULL) return;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int displayList(void)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return 1;
    }

    struct node *temp = head;
    printf("List: ");
    while(temp != NULL)
    {
        printf("[ %d ] -> ", temp->data);
        temp = temp->next;
    }
    printf("[ NULL ]\n");
    return 0;
}

int listLength(void)
{
    int count = 0;
    struct node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int insertFront(int value)
{
    struct node *newNode = createNode(value);
    if(newNode == NULL) return 1;

    newNode->next = head;
    head = newNode;
    printf("Inserted %d at front.\n", value);
    displayList();
    return 0;
}

int insertAtPosition(int value, int position)
{
    int len = listLength();
    if(position < 1 || position > len + 1)
    {
        printf("Invalid position.\n");
        return 1;
    }

    if(position == 1)
    {
        return insertFront(value);
    }

    struct node *newNode = createNode(value);
    if(newNode == NULL) return 1;

    struct node *temp = head;
    for(int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, position);
    displayList();
    return 0;
}

int insertEnd(int value)
{
    if(head == NULL)
    {
        return insertFront(value);
    }

    struct node *newNode = createNode(value);
    if(newNode == NULL) return 1;

    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    printf("Inserted %d at end.\n", value);
    displayList();
    return 0;
}

int deleteFront(void)
{
    if(head == NULL)
    {
        printf("List is empty. Cannot delete from front.\n");
        return 1;
    }

    struct node *temp = head;
    head = head->next;
    printf("Deleted %d from front.\n", temp->data);
    free(temp);

    if(head != NULL) displayList();
    else printf("List is now empty.\n");

    return 0;
}

int deleteAtPosition(int position)
{
    int len = listLength();
    if(position < 1 || position > len)
    {
        printf("Invalid position.\n");
        return 1;
    }

    if(position == 1)
    {
        return deleteFront();
    }

    struct node *prev = head;
    for(int i = 1; i < position - 1; i++)
    {
        prev = prev->next;
    }

    struct node *target = prev->next;
    prev->next = target->next;
    printf("Deleted %d from position %d.\n", target->data, position);
    free(target);

    if(head != NULL) displayList();
    else printf("List is now empty.\n");

    return 0;
}

int deleteEnd(void)
{
    if(head == NULL)
    {
        printf("List is empty. Cannot delete from end.\n");
        return 1;
    }

    if(head->next == NULL)
    {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        printf("List is now empty.\n");
        return 0;
    }

    struct node *prev = NULL;
    struct node *curr = head;
    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    printf("Deleted %d from end.\n", curr->data);
    free(curr);
    displayList();
    return 0;
}

void freeList(void)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}
