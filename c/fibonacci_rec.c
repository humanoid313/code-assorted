#include <stdio.h>
//#include <iostream>

// Calculate the nth fib number

int count = 0;
unsigned int fib(unsigned int n);
int main (int argc, char *argv[])
{
	unsigned int n = 0;
	while(n < 20){
		count = 0;
		fib(n);
		printf("%d\t%d\n",n, count);
		n++;		
	}

	return 0;
}

unsigned int fib(unsigned int n){
	count++;
	return (n < 2)? n : fib(n-1) + fib(n-2);
}


/*
//A recursive fib algorithm that uses memoization
int fib_dp (int n, int * memo) {
int n_1, n_2;


if (1 == n)
return 1;
else if (2 == n)
return 2;
else {
memo[n - 1] = fib_dp(n - 2, memo) + fib_dp(n - 1, memo);
return memo[n - 1];
}
}



//Test function
int main (int argc, char ** argv) {
int n = 0;
if (argv[1])
n = atoi(argv[1]);
else
cin >> n;
int * fib_memo = new int[n];
fib_memo[0] = 1;
fib_memo[1] = 2;
cout << "The " << n << "th fib number is:\t" << "rec\t" << fib_rec(n) << "\titer\t" << fib_interative(n) <<"\tDP:\t" << fib_dp(n, fib_memo) << endl;
while(n--)
cout << n + 1 << "th fib number is:\t" << fib_memo[n] << endl;
delete [] fib_memo;


return 0;
}

*/
