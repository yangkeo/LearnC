#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main01(void)
{
	//ÿ�����Ͷ���char *
	char *p0 = "1111111";
	char *p1 = "0000000";
	char *p2 = "bbbbbbb";
	char *p3 = "aaaaaaa";
	
	//ָ�����飬ָ���������һ�����飬ÿһ��Ԫ�ض���char *ָ��
	char *p[] = { "1111111", "0000000", "bbbbbbb", "aaaaaaa" };//������������ͬ
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

	//char *p[] = { "1111111", "0000000", "bbbbbbb", "aaaaaaa" };//������������ͬ
	/////char **p = { "1111111", "0000000", "bbbbbbb", "aaaaaaa" };//err
	int i = 0;
	int j = 0;
 	char *tmp = NULL;
	/*printf("����ǰ��\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", p[i]);
	}
	printf("\n");
	*/
	//ѡ������
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
	printf("�����\n");
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
	char *p[] = { "1111111", "0000000", "aaaaaaa", "bbbbbbb" };//������������ͬ
	int n = sizeof(p) / sizeof(p[0]);
	

	printf("����ǰ��\n");
	printf_array(p, n);
	
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", p[i]);
	}

	main02(&p[0], n);

	printf("�����\n");
	printf_array(p, n);
	
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", p[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}
