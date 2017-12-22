# Sprint Challenge: Processes and Scheduling

## Multiple Choice and Short Answer Questions

Add your answers to the Answers.md doc.

1. Assume we have two processes, P1 and P2, that have both been initialized, and let's assume that each 
   process on this machine is initially allocated 32 KB of memory as its address space. What are the 
   possible address space ranges each process could have? Write a short paragraph explaining your answer.

	a. P1: 0 - 32,000;
	   P2: 32,001 - 64,000
	
	b. P1: 0 - 64,000;
	   P2: 0 - 64,000
	
	c. P1: 32,001 - 64,000;
	   P2: 0 - 32,000

2. List all of the possible states a process may be in at any point in time. Briefly explain what each of 
   these states mean.

3. On your machine, how much faster does a `printf` call take compared to how long a `write` system call 
   takes?

4. `printf` is a C library function that calls the `write` system call under the hood. What are some 
    possible reasons as to why `printf` runs faster than `write`?

## Programming Exercise 1

Add your code in the `ex1/ex1.c` file.

Write a function that allocates an array of `int`s of a specified size.
(The `cols` parameter holds the size.)

```c
int *alloc_1d(int cols)
{
	// !!! IMPLEMENT ME
	// (solution is about 2 lines of code)
}

void alloc_1d_example(void)
{
	int *my_array = alloc_1d(12);

	my_array[8] = 3490;

	// The same array access could be made with pointer arithmetic:
	*(my_array+8) = 3490;

	// By the C spec, the array notation and pointer arithmetic notation
	// are 100% equivalent.

	printf("my_array[8] = %d\n", my_array[8]);
}
```

## Programming Exercise 2

Add your code in the `ex2/ex2.c` file.

Write a function that allocates a two-dimensional array of `int`s of a
specified size. (The `rows` parameter is how many rows in the array, and
`cols` is how many columns per row.)

```c
int **alloc_2d(int rows, int cols)
{
	// !!! IMPLEMENT ME
	// (solution is about 5 lines of code)
}

void alloc_2d_example(void)
{
	int **my_array = alloc_2d(5, 10);

	// First array index is row, second is column:
	my_array[2][3] = 3490;

	// The same array access could be made with pointer arithmetic:
	*(*(my_array+2)+3) = 3490;

	// By the C spec, the array notation and pointer arithmetic notation
	// are 100% equivalent.
	
	printf("my_array[2][3] = %d\n", my_array[2][3]);
}
```
