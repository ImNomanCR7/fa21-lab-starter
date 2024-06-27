#include<stdio.h>

int main()
{
	unsigned int x,y;
	x=42;
	y=24;
	/* __asm__ volatile ("add %0 %1" : outputs : inputs : clobbers); */
	
	__asm__ volatile ("add %1, %0" : "=r" (x): "r" (y) : "cc");
	printf("Hello World, %d\n", x);
	printf("GoodBye World, %d\n", y);
}

