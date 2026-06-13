# Linked List Traversal

---

### Input: Head pointer of singly linked list.
### Output: Node values in sequence and total node count.

### Steps:
    
    1. if list is empty then
        1.1. print "List is empty"
        1.2. stop
    2. end if
    3. set temp = head
    4. set count = 0
    5. while temp is not NULL do
        5.1. print temp.data
        5.2. count = count + 1
        5.3. temp = temp.next
    6. end while
    7. print count
    8. stop

---
