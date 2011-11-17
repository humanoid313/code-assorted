#include <stdio.h>
#include <string.h>
//void string_reverse1(char *);
//char *string_reverse2(const char *string);
void remove_spaces(char *str);
int main ()
{
	char str[] = "Test sentence abc defg" ;
    char str2[] = "Test" ;
    char *str3;
	printf("%s\n", str);

//	string_reverse1(str);
//	printf("%s\n", str);
//    str3 = string_reverse2(str2);
	remove_spaces(str);
    printf("%s\n", str);
	return 0;
}
/*
//void string_reverse1(char *str)
{
  	char temp;
	int len=0, i;
    while(str[len]) len++;
    for(i=0; i < (int)(len/2); i++){
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

char *string_reverse2(const char *string1)
{
    int len = strlen(string1), i;
    char *str2 = (char *)malloc(len);
    for(i=0; i<len; i++){
        str2[i] = string1[len-i-1];
    }
    str2[len] = '\0';
    return str2;
}
*/
void remove_spaces(char *str){
	int i = 0, j=0, count = 0;
	while(str[i]){
		if(str[i] == ' ' ){
			count++;		// Count the number of spaces
			j = i;
			while(str[j+1]){
			 str[j] = str[j+1];
			 j++;
			}
		}
		
		i++;
	}
	str[i-count] = '\0';
}
