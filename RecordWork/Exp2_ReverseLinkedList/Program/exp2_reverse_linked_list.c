/** ===== Experiment 2: Reverse Linked List (Iterative and Recursive) ===== **/

/** ===== Documentation ===== **/
/*
 * This program reverses a singly linked list using:
 *  1. Iterative approach
 *  2. Recursive approach
 * It also supports display and rebuild operations for repeated testing.
 */

/** ===== Preprocessing Directives ===== **/
#include<stdio.h>
#include<stdlib.h>

/** ===== Global Declarations ===== **/
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
int buildList(void);
int displayList(void);
void freeList(void);
int reverseIterative(void);
struct node* reverseRecursiveHelper(struct node *node);
int reverseRecursive(void);

/** ===== Main Function ===== **/
int main(void)
{
    int choice, status = 0;

    printf("\n===== Experiment 2: Reverse Linked List =====\n");
    if(buildList())
    {
        return 1;
    }

    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Display List\n");
        printf("2. Reverse Iteratively\n");
        printf("3. Reverse Recursively\n");
        printf("4. Rebuild List\n");
        printf("5. Exit\n");
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
                if(reverseIterative()) status = 1;
                break;
            case 3:
                if(reverseRecursive()) status = 1;
                break;
            case 4:
                freeList();
                if(buildList()) status = 1;
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
                status = 1;
        }
    } while(choice != 5);

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

int buildList(void)
{
    int n, value;
    struct node *last = NULL;

    printf("Enter number of nodes: ");
    if(scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    if(n == 0)
    {
        head = NULL;
        printf("Created an empty list.\n");
        return 0;
    }

    printf("Enter %d node values: ", n);
    for(int i = 0; i < n; i++)
    {
        if(scanf("%d", &value) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        struct node *newNode = createNode(value);
        if(newNode == NULL)
        {
            return 1;
        }

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;
    }

    printf("List created successfully.\n");
    displayList();
    return 0;
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

int reverseIterative(void)
{
    if(head == NULL)
    {
        printf("List is empty. Nothing to reverse.\n");
        return 1;
    }

    struct node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    printf("List reversed iteratively.\n");
    displayList();
    return 0;
}

struct node* reverseRecursiveHelper(struct node *node)
{
    if(node == NULL || node->next == NULL)
    {
        return node;
    }

    struct node *newHead = reverseRecursiveHelper(node->next);
    node->next->next = node;
    node->next = NULL;
    return newHead;
}

int reverseRecursive(void)
{
    if(head == NULL)
    {
        printf("List is empty. Nothing to reverse.\n");
        return 1;
    }

    head = reverseRecursiveHelper(head);
    printf("List reversed recursively.\n");
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
