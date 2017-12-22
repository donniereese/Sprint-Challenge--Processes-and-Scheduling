// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int **alloc_2d(int rows, int cols)
{
    int *row_arr = malloc(rows);
    
    for (int i = 0; i < cols; i++) {
        int *col_arr = malloc(cols);
        row_arr[i] = *col_arr;
    }
    return (&row_arr);
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


int main(int argc, char* argv[])
{
    // FILE * fp;
    
    // fp = fopen("text.txt", "w+");

    int rc = fork();

    alloc_2d_example();

    // fprintf(fp, "banana! %d\n", (int) getpid());
    
    return 0;
}
