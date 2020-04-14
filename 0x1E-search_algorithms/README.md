# 0x1E. C - Search Algorithms

## Description
What you should learn from this project:

* What is a search algorithm
* What is a linear search
* What is a binary search
* What is the best search algorithm to use depending on your needs

---

### [0. Linear search](./0-linear.c)
* Write a function that searches for a value in an array of integers using the Linear search algorithm


### [1. Binary search](./1-binary.c)
* Write a function that searches for a value in a sorted array of integers using the Binary search algorithm


### [2. Big O #0](./2-O)
* What is the time complexity (worst case) of a linear search in an array of size n?


### [3. Big O #1](./3-O)
* What is the space complexity (worst case) of an iterative linear search algorithm in an array of size n?


### [4. Big O #2](./4-O)
* What is the time complexity (worst case) of a binary search in an array of size n?


### [5. Big O #3](./5-O)
* What is the space complexity (worst case) of a binary search in an array of size n?


### [6. Big O #4](./6-O)
* What is the space complexity of this function / algorithm?


### [7. Jump search](./100-jump.c)
* Write a function that searches for a value in a sorted array of integers using the Jump search algorithm


### [8. Big O #5](./101-O)
* What is the time complexity (average case) of a jump search in an array of size n, using step = sqrt(n)?


### [9. Interpolation search](./102-interpolation.c)
* Write a function that searches for a value in a sorted array of integers using the Interpolation search algorithm


### [10. Exponential search](./103-exponential.c)
* Write a function that searches for a value in a sorted array of integers using the Exponential search algorithm


### [11. Advanced binary search](./104-advanced_binary.c)
* You may have noticed that the basic binary search does not necessarily return the index of the first value in the array (if this value appears more than once in the array).
In this exercise, you’ll have to solve this problem.


### [12. Jump search in a singly linked list](./105-jump_list.c)
* You might think that linear search is not as effective as any other algorithm, right? Well, we should see what happens with a singly linked list.


### [13. Linear search in a skip list](./106-linear_skip.c)
* As you see now, looking for a specific value in a singly linked list always leads to browse every element of the list.
A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it.
A linked list with an express lane is called a skip list.
This change does not come without consequences. Indeed, the space complexity of a search in this kind of list will grow as sizeof(skiplist_t) > sizeof(listint_t) (see example below).


### [14. Big O #6](./107-O)
* What is the time complexity (average case) of a jump search in a singly linked list of size n, using step = sqrt(n)?


### [15. Big O #7](./108-O)
* What is the time complexity (average case) of a jump search in a skip list of size n, with an express lane using step = sqrt(n)?

---

## Author
* **Jhoan Stiven Zamora Caicedo** - [jzamora5](https://github.com/jzamora5)