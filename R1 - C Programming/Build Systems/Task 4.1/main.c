#include<stdio.h>
#include "header.h"

int main(){
	int x,y;
	int sum = 0;
	
	printf("Enter the value of x: \n");
	scanf("%d", &x);
	
	printf("Enter the value of y: \n");
	scanf("%d", &y);
	
	sum = add (&x, &y);
	
	printf("Sum is = %d\n", sum);
	
	return 0;
}
