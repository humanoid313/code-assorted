#include <stdio.h>
//	#include <iostream>
int main (int argc, char *argv[])
{
	long double seed1 = 0L, seed2 = 1L, num;
	unsigned long int count = 0; 
	unsigned int max_count = 100;
	while(count < max_count){
		num = seed1 + seed2;
		seed1 = seed2;
		seed2 = num;
		printf("%.0Lf  ", num);
		count++;
	}
	return 0;
}
