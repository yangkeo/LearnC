#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	char *p = NULL;
	char *q = NULL;
	int i = 0;
	char buf[100] = "asfdsff";

	p = &buf[0];
	printf("p1 = %d, %c\n", p ,*p);

	p = &buf[1];
	printf("p2 = %d, %c\n\n", p, *p);

	for(i = 0; i < strlen(buf); i++)
	{
		p = buf + i;
		printf("p3 = %d, %c\n", p, *p);
	}


	q = (char*)malloc(100);
	if(q == NULL)
	{
		return -1;
	}

	strcpy(q, ";aodfhv");

	printf("\n");
	system("pause");
	return 0;
}


