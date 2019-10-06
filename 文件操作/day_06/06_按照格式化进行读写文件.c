#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

void my_fprintf(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");  //"w+"意思是若文件不存在则创建文件，若已存在则清空文件
	if (fp == NULL)
	{
		perror("my_fprintf fopen error");
	}

	//fprintf(stdout, "hello, i am a pid, mike = %d\n", 250);
	fprintf(fp, "hello, i am a pid, mike = %d\n", 250); 
	
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fscanf(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");  //"w+"意思是若文件不存在则创建文件，若已存在则清空文件
	if (fp == NULL)
	{
		perror("my_fread fopen error");
	}

	int a = 0;
	fscanf(fp, "hello, i am a pid, mike = %d\n", &a);
	printf("a = %d\n", a);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{

	my_fprintf("../06.txt");
	my_fscanf("../06.txt");

	printf("\n");
	system("pause");
	return 0;
}