#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char occurent(char str[]) {
	int min=strlen(str)+1 ;
	char ch;
	
	for(int i = 0; i <= strlen(str); i++) {
		ch=str[i];
		for(int j=i+1; j <= strlen(str); j++)
			if(str[j] == ch) {
		    if (j<min) min = j;
  			break;
  		}
	}
	if (min != strlen(str)+1)
		return str[min];
	return '\0';
}

int main() {
	char  y[100];
	printf("entrer un mot\n");
	scanf("%s",y);
	printf("Le premier caractere recurrent est :\t ");
	printf("%c\n",occurent(y));
	return 0;
}
