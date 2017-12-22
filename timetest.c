#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

void get_instruction_time(int instr, double *avg)
{
    // 0 = printf
    // 1 = write
    struct timespec start, end;
    long sum = 0;

    if (instr == 1) {
        printf("Testing WRITE\n");
        for (int i = 0; i < number_iter; i++) {
            clock_gettime(CLOCK_MONOTONIC, &start);
            write(fileno(stdout), "", 0);
            clock_gettime(CLOCK_MONOTONIC, &end);
            long difference = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
            sum += difference;
        }
    } else {
        printf("Testing PRINTF\n");
        for (int i = 0; i < number_iter; i++) {
            clock_gettime(CLOCK_MONOTONIC, &start);
            printf("");
            clock_gettime(CLOCK_MONOTONIC, &end);
            long difference = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
            sum += difference;
            printf("%ld\n", sum);
        }
    }

    *avg = sum / (float) number_iter;
}


int main(void) {
    double *avg = 0;

    get_instruction_time(0, avg);
    printf("Average time it takes to make a write system call is %f ns.\n", *avg);

    get_instruction_time(1, avg);
    printf("Average time it takes to write with printf is %f ns.\n", *avg);



    return 0;
}
