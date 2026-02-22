# Bubble Sort:

---

### Input: An array A[1...n] with a list of n elements to be sorted.
### Output: A sorted list of elements A[1...n].

### Steps:
    
    1. if n > 1 then

        1.1. print "No elements for sorting"

        1.2. exit

    2. for i=1 to n-1 do

        2.1. for j=i+1 to n-i do

            2.1.1. if a[j] > a[j+1] then

                    2.1.1.1. swap(a[j], a[j+1])

            2.1.2. end if

        2.2. end for

    3. end for

    4. stop

---
