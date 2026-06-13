/** ===== Experiment 3: Linked List Traversal and Manipulation ===== **/

/** ===== Documentation ===== **/
/*
 * This program demonstrates linked list traversal and manipulation.
 * Operations available:
 *  1. Display list (traversal)
 *  2. Count nodes
 *  3. Search by value
 *  4. Update node value at position
 *  5. Find middle node
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
int countNodes(void);
int searchValue(int key);
int updateAtPosition(int position, int newValue);
int findMiddle(void);
void freeList(void);

/** ===== Main Function ===== **/
int main(void)
{
    int choice, key, pos, newValue, status = 0;

    printf("\n===== Experiment 3: Linked List Traversal and Manipulation =====\n");
    if(buildList())
    {
        return 1;
    }

    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Traverse and Display\n");
        printf("2. Count Nodes\n");
        printf("3. Search Value\n");
        printf("4. Update Value at Position\n");
        printf("5. Find Middle Node\n");
        printf("6. Exit\n");
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
                printf("Total nodes: %d\n", countNodes());
                break;
            case 3:
                printf("Enter value to search: ");
                if(scanf("%d", &key) != 1 || searchValue(key)) status = 1;
                break;
            case 4:
                printf("Enter position (1-based) and new value: ");
                if(scanf("%d %d", &pos, &newValue) != 2 || updateAtPosition(pos, newValue)) status = 1;
                break;
            case 5:
                if(findMiddle()) status = 1;
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid menu choice.\n");
                status = 1;
        }
    } while(choice != 6);

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
        printf("Created an empty list.\n");
        head = NULL;
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

int countNodes(void)
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

int searchValue(int key)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return 1;
    }

    int position = 1;
    struct node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("%d found at position %d.\n", key, position);
            return 0;
        }
        temp = temp->next;
        position++;
    }

    printf("%d not found in the list.\n", key);
    return 1;
}

int updateAtPosition(int position, int newValue)
{
    int len = countNodes();
    if(position < 1 || position > len)
    {
        printf("Invalid position.\n");
        return 1;
    }

    struct node *temp = head;
    for(int i = 1; i < position; i++)
    {
        temp = temp->next;
    }

    printf("Updated node at position %d from %d to %d.\n", position, temp->data, newValue);
    temp->data = newValue;
    displayList();
    return 0;
}

int findMiddle(void)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return 1;
    }

    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle node value: %d\n", slow->data);
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
