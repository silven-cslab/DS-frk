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
