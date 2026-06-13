# Singly Linked List Deletion

---

### Input: Head pointer of list, deletion choice (front/position/end), optional position.
### Output: Updated singly linked list after deletion.

### Steps:
    
    1. if list is empty then
        1.1. print "List is empty"
        1.2. stop
    2. end if
    3. if choice is front then
        3.1. temp = head
        3.2. head = head.next
        3.3. free temp
    4. else if choice is position then
        4.1. if position is invalid then
            4.1.1. print "Invalid position"
            4.1.2. stop
        4.2. end if
        4.3. traverse to node before position
        4.4. if target node is NULL then
            4.4.1. print "Position out of range"
            4.4.2. stop
        4.5. end if
        4.6. unlink target node and free it
    5. else
        5.1. if list has one node then
            5.1.1. free node
            5.1.2. set head = NULL
        5.2. else
            5.2.1. traverse to second last node
            5.2.2. free last node
            5.2.3. set second_last.next = NULL
        5.3. end if
    6. end if
    7. display updated list
    8. stop

---
