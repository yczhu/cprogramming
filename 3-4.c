#include <stdio.h>

#define MAX_INT ((unsigned) (-1) >> 1)
#define MIN_INT (MAX_INT + 1)

int main()
{
    printf("Size of int: %lu\n", sizeof(int));
    
    printf("MAX: %d\n", MAX_INT);
    printf("MIN: %d\n", MIN_INT);
    printf("MAX+1: %d\n", MAX_INT+1);
    printf("-MIN: %d\n", -MIN_INT);
    return 0;
}
