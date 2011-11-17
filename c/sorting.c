//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define arraysize 20
//using namespace std;

void printarray(int *arr){
    int count;
    for(count = 0; count <arraysize; count++)
        printf("%d ", arr[count]);
    printf("\n");
}
void bubblesort(int *arr){
    int i,j,swapcount = 0,stepcount=0, temp;
    for(i = 0; i< arraysize; i++){
        for(j=0; j<arraysize-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j] ;
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapcount++;
            }
            stepcount++;
        }
    }
    printf("Swaps :%d\tSteps :%d\n", swapcount, stepcount);
}

void selectionsort(int *arr){
    int min, i, j, swapcount=0, stepcount=0, indx, temp;
    /* Program will crash if ordered input is passed as indx will be undefined
        using indx = i solves this but is better to use a flag to control etc.*/
    for(i=0; i<arraysize; i++){
        min = arr[i]; indx = i;
        for(j=i+1; j<arraysize; j++){
            if(arr[j] < min){
                min = arr[j];
                indx = j; printf("hret");
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[indx] = temp;
        stepcount++;
    }
    //printf("Swaps :%d\tSteps :%d\n", swapcount, stepcount);
}

void insertionsort(int *arr){
    int j, p, temp, stepcount=0;

    for(p=2; p<arraysize; p++){
        temp = arr[p];
        for(j=p; temp < arr[j-1]; j--){
            arr[j] = arr[j-1];
            stepcount++;
        }
        arr[j] = temp;
    }
    printf("Steps :%d\n", stepcount);
}



int main(){
    int a[arraysize];
    int count;
    for(count=0; count <arraysize; count++){
        a[count] = rand();
    }
    printarray(a);
    //bubblesort(a);
    //selectionsort(a);
    insertionsort(a);
    printarray(a);
	return 0;
}
