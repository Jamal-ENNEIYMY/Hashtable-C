#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char occurent(char str[])
{
    int min=strlen(str)+1 ;
    char ch;
    int i,j;
    for( i = 0; i <= strlen(str); i++)
  	{
  	    ch=str[i];
  	    for(j=i+1; j <= strlen(str); j++)
  		if(str[j] == ch)
		{
		    if (j<min) min=j;
  			break;
 		}
	}
	if (min!=strlen(str)+1) {
            printf("Le premier caractere recurrent est :\t ");
            return str[min];

	}
	return NULL;

}

int main()
{
    int i;
    char  y[100];
    for(i=0;i<100;i++){
        y[i]=0;
    }
    printf("entrer un mot\n");
    scanf("%s",y);
    printf("%c",occurent(y));
    return 0;
}

