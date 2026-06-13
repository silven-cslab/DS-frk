# Singly Linked List Insertion

---

### Input: Head pointer of list, value to insert, insertion choice (front/position/end), optional position.
### Output: Updated singly linked list after insertion.

### Steps:
    
    1. if memory allocation for new node fails then
        1.1. print "Memory allocation failed"
        1.2. stop
    2. end if
    3. if choice is front then
        3.1. set new.next = head
        3.2. set head = new
    4. else if choice is position then
        4.1. if position is invalid then
            4.1.1. print "Invalid position"
            4.1.2. free new node
            4.1.3. stop
        4.2. end if
        4.3. traverse to node before position
        4.4. set new.next = prev.next
        4.5. set prev.next = new
    5. else
        5.1. if list is empty then
            5.1.1. set head = new
        5.2. else
            5.2.1. traverse to last node
            5.2.2. set last.next = new
        5.3. end if
    6. end if
    7. display updated list
    8. stop

---
