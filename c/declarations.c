#include <stdio.h>
typedef char (*array_ptr) [100]; 	// Pointer to array of 100 chars
//typedef char *array_ptr [100];		// Array of 100 char pointers
int main(){

	int *abc;
	array_ptr aa;
	printf("%d\n", sizeof *abc );	// Perfectly valid. Sizeof is an operator.
}

