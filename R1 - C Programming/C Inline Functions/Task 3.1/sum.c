
/* 
* Author: Noman Rafiq
* Dated: June 25, 2024
* Description: The programs takes two inputs (x & y) from the user and outputs the sum of them using inline assembly.
*/ 

#include<stdio.h>

int main(){
	unsigned int x,y;
	
	//Takes x
	printf("Enter x: \n");
	scanf("%u", &x);
	
	//Takes y
	printf("Enter y: \n");
	scanf("%u", &y);
	
	//Inline Assembly
	__asm__ volatile ("add %1, %0" : "+r" (x) : "r" (y) : "cc");
	
	printf("Sum is = %u\n", x);
}
