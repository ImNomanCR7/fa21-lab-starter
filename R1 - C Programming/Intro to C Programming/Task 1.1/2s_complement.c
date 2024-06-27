#include <stdio.h>

void decToBin(int dec) {
    for (int bit = 15; bit >= 0; bit--) {
        int k = (unsigned int)dec >> bit;
        printf("%d", (k & 1) ? 1 : 0);
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Please Enter a Number: ");
    scanf("%d", &n);
    decToBin(n);

    // 2's Complement
    short complement = ~n + 1;
    
    printf("Two's Complement: ");
    for (int bit = 15; bit >= 0; bit--){
        printf("%d", (complement >> bit) & 1);
    }
    
    printf("\n");
    return 0;
}
