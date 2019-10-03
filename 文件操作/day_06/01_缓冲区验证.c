#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	char buf[] = "this is a test";
	FILE *fp = fopen("./test.txt", "w+");

	fputs(buf, fp);
	fclose(fp);


	printf("\n");
	system("pause");
	return 0;
}