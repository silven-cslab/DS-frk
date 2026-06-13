# Experiment 2: Reverse a Linked List (Iteratively and Recursively)

## Aim
To reverse a singly linked list using both iterative and recursive methods.

## Theory
Reversing a linked list changes every node link direction. Iterative reversal uses three pointers (`prev`, `curr`, `next`) and runs in O(n) time with O(1) extra space. Recursive reversal uses call stack to reverse links during unwinding and also runs in O(n) time.

## Description
Create a menu-driven C program to:
1. Build a singly linked list from user input.
2. Reverse the list iteratively.
3. Reverse the list recursively.
4. Display list before and after each reverse operation.
5. Handle empty and single-node lists safely.

## Algorithm

### Part 1
# Reverse Linked List (Iterative Method)

---

### Input: Head pointer of singly linked list.
### Output: Head pointer of reversed singly linked list.

### Steps:
    
    1. if list is empty or has one node then
        1.1. return head
    2. end if
    3. set prev = NULL
    4. set curr = head
    5. while curr is not NULL do
        5.1. set next = curr.next
        5.2. set curr.next = prev
        5.3. set prev = curr
        5.4. set curr = next
    6. end while
    7. set head = prev
    8. return head
    9. stop

---

### Part 2
# Reverse Linked List (Recursive Method)

---

### Input: Head pointer of singly linked list.
### Output: Head pointer of reversed singly linked list.

### Steps:
    
    1. define function reverseRecursive(node)
    2. if node is NULL or node.next is NULL then
        2.1. return node
    3. end if
    4. new_head = reverseRecursive(node.next)
    5. set node.next.next = node
    6. set node.next = NULL
    7. return new_head
    8. in main logic, set head = reverseRecursive(head)
    9. display reversed list
    10. stop

---

## C Program
```c
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
```

## Sample Output
```text
=== Test Run 1: Iterative and recursive reverse ===

===== Experiment 2: Reverse Linked List =====
Enter number of nodes: Enter 5 node values: List created successfully.
List: [ 1 ] -> [ 2 ] -> [ 3 ] -> [ 4 ] -> [ 5 ] -> [ NULL ]

----------- MENU -----------
1. Display List
2. Reverse Iteratively
3. Reverse Recursively
4. Rebuild List
5. Exit
Enter your choice: List reversed iteratively.
List: [ 5 ] -> [ 4 ] -> [ 3 ] -> [ 2 ] -> [ 1 ] -> [ NULL ]

----------- MENU -----------
1. Display List
2. Reverse Iteratively
3. Reverse Recursively
4. Rebuild List
5. Exit
Enter your choice: List reversed recursively.
List: [ 1 ] -> [ 2 ] -> [ 3 ] -> [ 4 ] -> [ 5 ] -> [ NULL ]

----------- MENU -----------
1. Display List
2. Reverse Iteratively
3. Reverse Recursively
4. Rebuild List
5. Exit
Enter your choice: Exiting...

=== Test Run 2: Edge case empty list ===

===== Experiment 2: Reverse Linked List =====
Enter number of nodes: Created an empty list.

----------- MENU -----------
1. Display List
2. Reverse Iteratively
3. Reverse Recursively
4. Rebuild List
5. Exit
Enter your choice: List is empty. Nothing to reverse.

----------- MENU -----------
1. Display List
2. Reverse Iteratively
3. Reverse Recursively
4. Rebuild List
5. Exit
Enter your choice: Exiting...
```
