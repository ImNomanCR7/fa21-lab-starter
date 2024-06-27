#include<stdio.h>
#include "lms.h"

inline int is_copies_available(Book x){
	if (x.copies_available >= 1){
	printf("Yes, %d Copies are available.\n", x.copies_available);
	}
	
	else{
	printf("No Copies Available.\n");
	}
	return 0;
}

inline Book print_book_details (Book y){
	printf("\n--------Book Details--------\n");
	printf("Title: %s\n", y.title);
	printf("Author: %s\n", y.author);
	printf("ISBN: %s\n", y.ISBN);
	printf("Publication Year: %d\n", y.publication_year);
	printf("Genre: %s\n", y.genre);
	printf("Copies Available: %d\n", y.copies_available);
}
