#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void main(void)
{
	char *p0 = NULL;
	p0 = (char *)malloc(100);
	strcpy(p0, "sfsdfsdf");

	//10个char *，每一个的值都是空
	char *p[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = malloc(100);
		strcpy(p[i], "sdfsdfsdf");
	}
	int a[10];
	int *q = (int *)malloc(10 * sizeof(int));  //q[10]
	
	//动态分配一个数组，每个元素都是char *
	//char *ch[10]
	int n = 3;
	char **buf = (char **)malloc(n * sizeof(char *));  //类似char *buf[3] (但不等价)
	if (buf == NULL)
	{
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
		char str[30];
		sprintf(str, "test%d%d", i, i);
		strcpy(buf[i], str);
	}
	
	for (i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
	}	
	//int k = 0;
	//char p3[10][30] = { "1111", "2222", "3333" };
	//k = sizeof(p3) / sizeof(p3[0]);
	//printf("k = %d\n", k);

	printf("\n");
	system("pause");
	return 0;

}


char **getMen(int n)
{
	int i = 0;
	char **buf = (char **)malloc(n * sizeof(char *));  //类似char *buf[3] (但不等价)
	if (buf == NULL)
	{
		return NULL;
	}
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
		char str[30];
		sprintf(str, "test%d%d", i, i);
		strcpy(buf[i], str);
	}

	return buf;
}

void printf_buf(char **buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s, ", buf[i]);
	}
	printf("\n");
}

void free_buf(char **buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}

void main02(void)
{
	char **buf = NULL;
	int n = 3;

	buf = getMen(n);
	if (buf = NULL)
	{
		printf("getMen err");
		return -1;
	}
	//printf_buf(buf, n);
	free_buf(buf, n);
	buf = NULL;

	printf("\n");
	system("pause");
	return 0;
}



