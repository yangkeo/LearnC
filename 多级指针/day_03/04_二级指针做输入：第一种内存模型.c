#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main01(void)
{
	//每个类型都是char *
	char *p0 = "1111111";
	char *p1 = "0000000";
	char *p2 = "bbbbbbb";
	char *p3 = "aaaaaaa";
	
	//指针数组，指针的数组是一个数组，每一个元素都是char *指针
	char *p[] = { "1111111", "0000000", "bbbbbbb", "aaaaaaa" };//和上面四种相同
	int n = sizeof(p) / sizeof(p[0]);

	printf("%d\n", n);

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", p[i]);
	}



	printf("\n");
	system("pause");
	return 0;
}


int main02(char **p, int n)
{

	//char *p[] = { "1111111", "0000000", "bbbbbbb", "aaaaaaa" };//和上面四种相同
	/////char **p = { "1111111", "0000000", "bbbbbbb", "aaaaaaa" };//err
	int i = 0;
	int j = 0;
 	char *tmp = NULL;
	/*printf("排序前：\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", p[i]);
	}
	printf("\n");
	*/
	//选择法排序
	for (i = 0; i < 4 - 1; i++)
	{
		for (j = i + 1; j < 4 - 1; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{

				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	/*
	printf("排序后：\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", p[i]);
	}
	


	
	printf("\n");
	system("pause");
	return 0;
	*/
}

void printf_array(char *p[], int n)
{
	int i = 0;
	for (i = 0; i < n ; i++)
	{
		printf(" %s\n", p[i]);
	}
}


int main(void)
{
	char *p[] = { "1111111", "0000000", "aaaaaaa", "bbbbbbb" };//和上面四种相同
	int n = sizeof(p) / sizeof(p[0]);
	

	printf("排序前：\n");
	printf_array(p, n);
	
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", p[i]);
	}

	main02(&p[0], n);

	printf("排序后：\n");
	printf_array(p, n);
	
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", p[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
