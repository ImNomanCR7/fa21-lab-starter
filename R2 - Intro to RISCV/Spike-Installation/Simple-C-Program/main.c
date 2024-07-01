#include<stdio.h>

int main()
{	int x,y;
	printf("Enter two Numbers (x, y):\n");
	scanf("%d\n", &x);
	printf("\n");
	scanf("%d", &y);
	
	int sum = 0;
	sum = x + y;
	
	printf("Sum of x and y is: %d\n", sum);
	return 0;
}
