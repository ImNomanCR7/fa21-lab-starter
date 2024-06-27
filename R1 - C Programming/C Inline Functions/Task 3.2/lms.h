
typedef struct Book {
	char title[30];
	char author[30];
	char ISBN[13];
	int publication_year;
	char genre[30];
	int copies_available;
	} Book;

int is_copies_available(Book x);
Book print_book_details(Book y);

