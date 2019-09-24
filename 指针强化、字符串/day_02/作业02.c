#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int getStr1Str2(char *source,  char *buf1, char *buf2)
{
	int i = 0;
	char replace[100] = { 0 };
	strcpy(replace, source);	
	

	for(i = 0; i < strlen(replace); i++)
	{
		if((i%2) == 1)
		{
			buf2[i-1] = replace[i];
		}
		else
		{
			if(i = 0)
			{
				buf1[i] = replace[i];
			}
			else
			{
			    buf1[i-1] = replace[i];
			}
		}
	}
	
	return 0;
}


int main(void)
{
	char source[] = "1a2b3d4z";
	char buf1[100] = { 'a' };
	char buf2[100] = { 'a' };
	
	printf("strlen(source) = %d\n", strlen(source));
	getStr1Str2(source, buf1, buf2);
	printf("buf1 = %s,    buf2 = %s\n", buf1, buf2);


	printf("\n");
	system("pause");
	return 0; 
}