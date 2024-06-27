
/*
	* Author: Noman Rafiq
	* Dated: June 26, 2024
	* Description: The programs prompts the user to Enter a number. Then the program uses a counter to count the number of zeroes in the right most position of the number using bitwise & operation.
	The counter keeps incrementing by 1 until the first occurance of the bit '1' is reached in the number.
*/

#include <stdio.h>
int trailing_zeros(int n){
    int count=0;

    //Keep Repeating until we find first '1' in the right most position of the number    
    while ((n & 1) == 0){
        count++;
        n >>= 1;
    }
    return count;
}


int main() {
    unsigned int x;
    printf("Enter a Number: \n");
    scanf("%u", &x);
    
    //Trailing Zero's
    int n = trailing_zeros(x);
    
    printf("Number of Trailing Zeros: %d\n", n);

    return 0;
}
