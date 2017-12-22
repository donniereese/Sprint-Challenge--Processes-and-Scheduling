#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int *alloc_1d(int cols)
{
	int *col_allocated = malloc(cols);
    return col_allocated;
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



int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();

    x++;
    int *tar = alloc_1d(x + 2);
    tar[x] = x;
    
    if (rc < 0) {
        fprintf(stderr, "Fork failed; exiting...\n");
        exit(1);
    } else if (rc == 0) {
        // child process satisfies this branch(? what does that mean)
        printf("Hello, child here at (pid: %d) \n", (int) getpid());
        printf("tar: %d\n", tar[x]);
    } else {
        x++;
        printf("Hello, parent here at (pid: %d), of the child %D\n", (int) getpid(), rc);
        printf("tar: %d\n", tar[x]);
    }
    return 0;
}