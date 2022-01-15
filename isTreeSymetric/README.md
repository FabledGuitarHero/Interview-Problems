# isTreeSymetic Algorithm

### Description:  
Simple algorithm for testing if a *Binary Search Tree* or *Red Black Tree* is symetrical.  The algorithm traversing each layer *BST* and checking for symmetry.

### Example:
```
        1          <-- Loop 1
    /       \
   2         2     <-- Loop 2
 /   \     /   \
3     4   4     3  <-- Loop 3

Retuns: True

        1          <-- Loop 1
    /       \
   2         2     <-- Loop 2
 /   \     /   \
3     4   3     4  <-- Loop 3

Returns: False

        1          <-- Loop 1
    /       \
   2         3     <-- Loop 2
 /   \     /   \
4     4   4     4  <-- Loop 3

Returns: False
```

