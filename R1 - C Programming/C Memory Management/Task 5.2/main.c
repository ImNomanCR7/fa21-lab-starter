
/*
	* Author: Noman Rafiq
	* Dated: June 26, 2024
	* Description: The program dynamically allocates memory for an array without actually using malloc/reallocs directly in main.c. The programs also has different functions to populate the array as well as displaying the array.
*/

#include "header.h"

int main()
{	srand(time(NULL));
	//Allocating Memory
	integer *array = MALLOC(SIZE,integer);
	
	//Populating Array 
	initialize_memory(array, SIZE);
	
	//Show Array
	printf("Array Elements:\n");
	show_memory(array, SIZE);

	printf("\n");
	
	//Re-alloc
	integer *resized_array = REALLOC(array, SIZE * RESIZE_FACTOR);
	printf("\n");
	
	//Populate Resized Array
	populate_resized(resized_array, SIZE * RESIZE_FACTOR);
	
	//Displaying the Resized Array
	printf("Resized Array: \n");
	show_memory(resized_array, SIZE * RESIZE_FACTOR);
	
	free(resized_array);
	
  
  return EXIT_SUCCESS;
}
