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
