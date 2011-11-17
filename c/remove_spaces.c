//#include <iostream>
#include <stdio.h>
//using namespace std;
void remove_spaces(char *str){
    int i = 0, j=0, count = 0;
    while(str[i]){
        if(str[i] == ' ' ){
            count++;        // Count the number of spaces
            j = i;
            while(str[j+1]){
             str[j] = str[j+1];
             j++;
            }
        }

        i++;
    }
    str[i-count] = '\0';
    printf("%s\n", str );
}

void remove_spaces_2(char *str){
    int i = 0, j=0, count = 0;
    while(str[i]){
        if(str[i] == ' ' ){
            count++;        // Count the number of spaces
        }
        else{
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[i-count] = '\0';
    printf("%s\n", str );
}


int main(){
    char s[] = "Test input a   b c d";
    remove_spaces_2(s);
	return 0;
}
