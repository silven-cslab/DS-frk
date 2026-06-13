# Linked List Manipulation (Search, Update, Middle)

---

### Input: Head pointer of singly linked list, operation choice, search key/update position/update value.
### Output: Search result, updated list, or middle node value.

### Steps:
    
    1. if list is empty then
        1.1. print "List is empty"
        1.2. stop
    2. end if
    3. if operation is search then
        3.1. traverse list and compare each node with key
        3.2. if found then print position else print "Not found"
    4. else if operation is update then
        4.1. validate position
        4.2. traverse to given position
        4.3. replace old value with new value
        4.4. display updated list
    5. else
        5.1. set slow = head and fast = head
        5.2. while fast and fast.next exist do
            5.2.1. slow = slow.next
            5.2.2. fast = fast.next.next
        5.3. end while
        5.4. print slow.data as middle node
    6. end if
    7. stop

---
