#include <stdio.h>

#define MIN -2147483648
#define MAX 2147483647

int main(void) {
    int Underflow = MIN - 1;
    printf("MIN - 1 = %d\n", Underflow);
    printf("Underflow Has Occured\n\n");
    
    int Overflow = MAX + 1;
    printf("Max + 1 = %d\n", Overflow);
    printf("Overflow Has Occured\n");
    return 0;
}
