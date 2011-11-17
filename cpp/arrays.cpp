#include <iostream>
#include <cstdlib>
#include <string>

#define MAX_SIZE 4
using namespace std;
void rotate_matrix(int **, int, int);
void init_matrix(int **, int, int);
void print_matrix(int **, int, int);
void transpose_matrix(int **, int, int);

void test(void){
    /*

    string** a = new string * [2];
    a[0] = new string("TEst");
    a[1] = new string("Test2");
    cout<<a[0][0]<<endl;
    cout<<a[1][0]<<endl;*/

    string a[2];
    a[0] = "Test1";
    a[1] = "Test2";
    cout<<a[0]<<endl<<a[1]<<endl;

}
int main(){
    int i = MAX_SIZE; int j = MAX_SIZE;
    int count;
    int **a = new int* [i];
    //  Creation
    for(count = 0; count <i; count++)
        a[count] = new int [j];
    init_matrix(a, i, j);
    print_matrix(a, i, j);
    cout<<endl;

    transpose_matrix(a,i,j);
    print_matrix(a, i, j);
    cout<<endl;

    rotate_matrix(a,i,j);
    print_matrix(a, i, j);
    cout<<endl;

     // Deletion
    for (count = 0; count < i; count++)
        delete [] a[count];
    delete [] a;

    test();
	return 0;
}

void print_matrix(int **t, int rows, int cols){
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0;j<cols; j++)
            cout<<t[i][j]<<" ";
        cout<<endl;
    }
}

void init_matrix(int **t, int rows, int cols){
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0;j<cols; j++)
            t[i][j] = rand()%100;

    }
}
void transpose_matrix(int **t, int rows, int cols){
    int  i,j, temp;
    for(i=0; i<rows; i++){
        for(j=0;j<cols; j++){
            if( i<j){
                temp = t[i][j];
                t[i][j] = t[j][i];
                t[j][i] = temp;
            }
        }
    }
}

void rotate_matrix(int **t, int rows, int cols){
    int i, j, h;
    transpose_matrix(t, rows, cols);
    for(i=0; i<rows; i++){
        for(j=0;j<cols/2; j++){
            h = t[i][j];
            t[i][j] = t[i][cols-j-1];
            t[i][cols-j-1] = h;
        }
    }
}

