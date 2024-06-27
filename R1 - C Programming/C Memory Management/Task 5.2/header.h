#ifndef _HEADER_GUARD_
#define _HEADER_GUARD_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 5
#define RESIZE_FACTOR 2


#define malloc "Do not call malloc directly in main!"
#define realloc "Do not call realloc directly in main!"

#define MALLOC(num,type)  (type *)alloc( (num)* sizeof(type) )
#define REALLOC(ptr, num)  (typeof(ptr))re_allocate((ptr), (num) * sizeof(*(ptr)))

typedef int integer;

void *alloc(size_t);
void initialize_memory(int *, int);
void show_memory(int *, int);

//Re-alloc Function Prototype
void *re_allocate(void *, size_t);
//populate resized array
void populate_resized(int *, int);


#endif
