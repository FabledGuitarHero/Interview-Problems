# EquilibriumPoint

### Problem:  
Given an array of numbers, find the point of the array where the sum of the element before equals the sum of the elements after the index.

### Example:
```
[10, 5, 3, 5, 2, 2, 6, 8]
Answer: 4 
10 + 5 + 3   =   2 + 2 + 6 + 8
```

### Solution:
1)  Calculate the sum of all the elements.
2)  Set index at arr[0]
3)  Set new sum integer to element arr[0]
4)  Check if the sum integer is equal to the sum of all elements minus sum integer + current index
5)  If not, add current index to sum integer and incriment
6)  Repeat

