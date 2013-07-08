#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

unsigned int
reverse(register unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));

}

int main()
{
    unsigned int *ints = malloc(100000000*sizeof(unsigned int));
    unsigned int *ints2 = malloc(100000000*sizeof(unsigned int));
    for(unsigned int i = 0; i < 100000000; i++)
      ints[i] = rand();

    unsigned int *inptr = ints;
    unsigned int *outptr = ints2;
    unsigned int *endptr = ints + 100000000;
    // Starting the time measurement
    double start = omp_get_wtime();
    // Computations to be measured
    while(inptr != endptr)
    {
      (*outptr) = reverse(*inptr);
      inptr++;
      outptr++;
    }
    // Measuring the elapsed time
    double end = omp_get_wtime();
    // Time calculation (in seconds)
    printf("Time: %f seconds\n", end-start);

    free(ints);
    free(ints2);

    return 0;
}
