#include<stdio.h>
#include <ctype.h>
#include "lms.h"
#include<string.h>

/* 
* Author: Noman Rafiq
* Dated: June 25, 2024
* Description: The programs prompts the user to choose an action. Then based on decision, it calls of the two inline functions to effectively display the Book Information or check if the copies for a particular Book are available.
*/ 


int main(){

		
	/* ------- Book 1 ------- */
	Book A;
	strcpy(A.title, "Chemistry");
	strcpy(A.author, "Noman");
	strcpy(A.ISBN, "1234567890123");
	A.publication_year = 2014;
	strcpy(A.genre, "Science");
	A.copies_available = 3;
	
	
	/* ------- Book 2 ------- */
	Book B;
	strcpy(B.title, "Maths");
	strcpy(B.author, "Junaid");
	strcpy(B.ISBN, "2312837147149");
	B.publication_year = 2017;
	strcpy(B.genre, "Science");
	B.copies_available = 1;
	
	
	/* ------- Book 3 ------- */
	Book C;
	strcpy(C.title, "Physics");
	strcpy(C.author, "Ahmed");
	strcpy(C.ISBN, "3908887112777");
	C.publication_year = 2019;
	strcpy(C.genre, "Science");
	C.copies_available = 0;
	
	printf("Three Books are Stored in the LMS namely, A, B & C\n\n");
	printf("Please Select an Option?\n");
	printf("1. Book Details\n");
	printf("2. Check Available Copies\n");
	
	int option;
	scanf("%d", &option);
	
	char c;
	printf("Choose a Book from LMS (A, B, C)\n");
	
	scanf(" %c", &c);
	c = tolower(c);
	
	//Make a Choice
	if (option == 1){
		
		
		switch(c) {
		
		case 'a' : 
		print_book_details(A);
		break;
		
		case 'b' : 
		print_book_details(B);
		break;
		
		case 'c' : 
		print_book_details(C);
		break;
		
		default:
		printf("Invalid Input!\n");
		break;
		}
	
	}
	else if (option == 2){
		switch(c) {
		
		case 'a' : 
		is_copies_available(A);
		break;
		
		case 'b' : 
		is_copies_available(B);
		break;
		
		case 'c' : 
		is_copies_available(C);
		break;
		
		default:
		printf("Invalid Input!\n");
		break;
		}
		
	}
	
	else
	printf("Invalid Operation!\n");

	return 0;
}
