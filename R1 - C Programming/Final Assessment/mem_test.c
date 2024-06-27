#include <stdio.h>



//This C program verifies that data is correctly written into a memory array. It initializes two arrays: one with zeros ('Store Data') and one with expected values ('Store Expected data'). It then fills 'Store Data' with a specific sequence of bytes. The program compares these arrays and checks for any mismatches. If the data matches the expected pattern, it prints "PASS"; otherwise, it prints "FAIL" and shows where the mismatch occurred.

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS<<3

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));


arr_t store_byte_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };



int store_byte_test (arr_t *p) {

// EF, BE, AD, DE, EF, BE, AD, DE
	unsigned long long store_byte[] = { 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE };
	int b = 0;
	
	//Setting bits
	for (int i = 0; i < 8; i++){
	b = b + 2;
		store_byte [i+1] = store_byte [i+1] << (b*4);
	}
	
	//storing data
	for (int i = 0; i < 8; i++){
		p[i].double_word[0] = store_byte[i];
	}
	
	//Comparing Bytes
	for (int i = 0; i < 8; i++){
		
		if (p[i].double_word[0] != store_byte_expected_data[i].double_word[0]){
		
		printf("Mismatch at index %d:\n", i);
		printf("Expected: {0x%016llx, 0x%016llx}\n", store_byte_expected_data[i].double_word[0], store_byte_expected_data[i].double_word[1]);
		printf("Actual:   {0x%016llx, 0x%016llx}\n", p[i].double_word[0], p[i].double_word[1]);
		
		printf("Byte Test Failed!\n");
		return 0;
		}	
	}
	printf("Byte Test Passed!\n");	
} // store_byte_test


int store_half_word_test (arr_t *p) {

// BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
	unsigned long long store_half_word[] = { 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xDE, 0xEF };
	int b = 0;
	
	//Setting Bits
	for (int i = 0; i < 8; i++){
		b += 2;
		store_half_word[i+1] = 	store_half_word[i+1] << (b*4);
	}
	
	//Store_Halfwords
	for (int i = 0; i < 8; i++){
		p[i].double_word[0] = 	store_half_word[i];
		p[7].double_word[1] = 	store_half_word[8];
		
	}
	
	//Comparing Halfwords
	for (int i = 0; i < 8; i++){
		if ( (p[i].double_word[0] != store_half_word_expected_data[i].double_word[0]) || (p[7].double_word[1] !=  store_half_word_expected_data[7].double_word[1]) ){
		
		printf("Mismatch at index %d:\n", i);
		printf("Expected: {0x%016llx, 0x%016llx}\n", store_half_word_expected_data[i].double_word[0], store_half_word_expected_data[i].double_word[1]);
		printf("Actual:   {0x%016llx, 0x%016llx}\n", p[i].double_word[0], p[i].double_word[1]);
		
		printf("Halfword Test Failed!\n");
		return 0;
		}		
	}
	printf("Halfword Test Passed!\n");	

} // store_half_word_test


int store_word_test (arr_t *p) {

// DEADBEEF, F00DC0DE
	unsigned long long store_word[] = { 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE, 0xF0, 0xF00D, 0xF00DC0 };
	
	int b = 0;
	
	//Setting Bits
	for (int i = 0; i < 8; i++){
		b += 2;
		//printf("i = %d - - - - %llx\n", i, store_word[i+1]);
		store_word[i+1] = store_word[i+1] << (b * 4);
		//printf("i = %d - - - - %llx\n", i, store_word[i+1]);
	}
	
	//Store Words
	for (int i = 0; i < 8; i++){
		p[i].double_word[0] = store_word[i];
		p[5].double_word[1] = store_word[8];
		p[6].double_word[1] = store_word[9];
		p[7].double_word[1] = store_word[10];
	}
	
	//Comparing Words
	for (int i = 0; i < 8; i++){
	
		if ( ( p[i].double_word[0] != store_word_expected_data[i].double_word[0] ) || 
		( i>=5 && p[i].double_word[1] != store_word_expected_data[i].double_word[1] ))
		{
		
		printf("Mismatch at index %d:\n", i);
		printf("Expected: {0x%016llx, 0x%016llx}\n", store_word_expected_data[i].double_word[0], store_word_expected_data[i].double_word[1]);
		printf("Actual:   {0x%016llx, 0x%016llx}\n", p[i].double_word[0], p[i].double_word[1]);
		printf("Store Word Test Failed!\n");
		return 0;
		}
	}
	printf("Store Word Test Passed!\n");

} // store_word_test


int store_double_word_test (arr_t *p) {

// DEADBEEFF00DC0DE
	unsigned long long store_double_word[] = { 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDE, 0xDEAD, 0xDEADBE, 0xDEADBEEF, 0xDEADBEEFF0, 0xDEADBEEFF00D, 0xDEADBEEFF00DC0 };
	
	int b = 0;
	
	//Setting Bits
	for (int i = 0; i < 8; i++){
		b += 2;
		store_double_word[i+1] <<= b * 4;
	}
	
	
	int x = 8;
	//Storing Double Words
	for (int i = 0; i < 8; i++){
		p[i].double_word[0] = store_double_word[i];

		if ( i>=1 ){
		p[i].double_word[1] = store_double_word[x];
		x++;
		}
	}
	
	//Comparing Double Words
	for (int i = 0; i < 8; i++){
		if ( (p[i].double_word[0] != store_double_word_expected_data[i].double_word[0]) ||
		 ( i>=1 && p[i].double_word[1] != store_double_word_expected_data[i].double_word[1])){
		 
		printf("Mismatch at index %d:\n", i);
		printf("Expected: {0x%016llx, 0x%016llx}\n", store_double_word_expected_data[i].double_word[0], store_double_word_expected_data[i].double_word[1]);
		printf("Actual:   {0x%016llx, 0x%016llx}\n", p[i].double_word[0], p[i].double_word[1]);
		
		printf("Store Double Word Test Failed!\n");
		return 0;
		
		}
	}
		
		printf("Store Double Word Test Passed!\n");
} // store_double_word_test



int main() {

	printf("Running Tests..\n");
	store_byte_test(store_byte_data);
	store_half_word_test(store_half_word_data);
	store_word_test(store_word_data);
	store_double_word_test(store_double_word_data);
} // main
