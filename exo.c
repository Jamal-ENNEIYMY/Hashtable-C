#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char occurent(char str[]);

int main() {
    printf("%c \n",occurent("bqqbca"));
    return 0;
}

char occurent(char str[]) {
	int min=strlen(str)+1 ;
	char ch;
	int j;
	for(int i = 0; i <= strlen(str); i++) {
		ch=str[i];
	for(j=i+1; j <= strlen(str); j++)
		if(str[j] == ch) {
			if (j<min) min=j;
			break;
 		}
	}
	if (min!=strlen(str)+1) 
		return str[min];

	return '\0';
}
