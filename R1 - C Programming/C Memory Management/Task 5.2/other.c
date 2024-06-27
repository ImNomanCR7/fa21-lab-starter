#include "header.h"


// Only in this file you can directly call malloc, realloc, etc.
#undef malloc
 
void *alloc (size_t size){


  void *mempool;

  mempool = malloc(size);

  if (mempool != NULL) return mempool;
  
  else {
    printf("Out of memory");
    exit(EXIT_FAILURE);
  }

}

// Definition for initialize_memory
 void initialize_memory(int *arr, int n){
 	for (int i = 0; i < n; i++){
 		arr[i] = rand() % 100;
 	}
 }

// Definition for show_memory
void show_memory(int *arr, int n){
	for (int i = 0; i < n; i++){
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
}

//Re-alloc Function Definition
void *re_allocate(void *arr, size_t size){

	int *ptr = malloc(size);
	if (ptr != NULL){
	printf("Memory Created Successfully\n");
	memcpy(ptr, arr, size/2);
	free(arr);
	return ptr;
	}
	else {
	printf("Out of Memory\n");
	}
}

//Populate Resized Array
void populate_resized(int *arr, int n){
	for (int i = n/2; i < n; i++){
 		arr[i] = rand() % 100;
 	}	
}
