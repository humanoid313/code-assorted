// Compute maximum subsequence sum

#include <stdio.h>
#define max(x,y) x>y?x:y

int maxsum(int *, int);

int main(){
	
	int arr[] = {-2, 11, -4, 13, -5, -2};
	printf("%d\n", maxsum(arr, 6));
	return 0;
}

int maxsum(int *a, int size){
	int i = 0;
	int maxtillnow = 0; 
	int maxsubseq = 0;
	for (i=0; i<size; i++){
		maxtillnow = max(maxtillnow+a[i], 0 );
		maxsubseq = max(maxsubseq, maxtillnow);
	}
	return maxsubseq;
}




