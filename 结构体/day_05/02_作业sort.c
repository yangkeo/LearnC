#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
���ܣ�1��������p1���ַ���ȡ����
      2���Ѷ�ά����buf2���ַ�ȡ����
	  3��������ַ�������p3, p3���ڶ�������Ķ�ά�ڴ�
	  4����p3���ַ�����������ͨ�� strcmp()��������
������
     p1��ָ�������׵�ַ��char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	 len1��p1Ԫ�ظ���
	 buf2����ά������Ԫ�ص�ַ��buf2[10][30] = { "111111", "3333333", "222222" };
	 len2: buf2�ַ�������
	 p3������ָ��ĵ�ַ����Ҫ�ٺ����ڷ����ά�ڴ棬����p1��buf2���ַ���������Ҫ����
	 len3������p3���ַ�������
*/

int sort(char **array1, int num1, char(*array2)[30], int num2, char ***myp3 /*out*/, int *num3)
{
	if (array1 == NULL || array2 == NULL || myp3 == NULL)
	{
		return -1;
	}
	char **tmp = (char **)malloc((num1 + num2) * sizeof(char *));
	if (tmp == NULL)
	{
		return -2;
	}

	//��ÿ��ָ������ڴ棨ָ�������
	int i = 0, j = 0;
	for (i = 0; i < num1; i++)
	{
		tmp[i] = (char *)malloc(sizeof(char) * (strlen(array1[i]) + 1));
		strcpy(tmp[i], array1[i]);
	}
	for (i = num1, j = 0; j < num2; i++, j++)
	{
		tmp[i] = (char *)malloc(sizeof(char)* (strlen(array2[j]) + 1));
		strcpy(tmp[i], array2[j]);
	}

	int *p = NULL;
	for (i = 0; i < ((num1 + num2) - 1); i++)
	{
		for (j = 0; j < (num1 + num2); j++)
		{
			if (strcmp(tmp[i] , tmp[j]) > 0)
			{
				/*strcpy(p, tmp[i]);
				strcpy(tmp[i], tmp[j]);    //err: ���ֽ�����ʽ��ֵ��������Ϊ�ڴ���С��һ���Ի����
				strcpy(tmp[j], p);*/
				//ָ��ָ�򽻻�
				p = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = p;
			}
		}
	}

	//��Ӹ�ֵ��ָ������������
	*myp3 = tmp;
	*num3 = num1 + num2;


	return 0;
}
void free_malloc(char ***p, int n)
{
	if (p == NULL)
	{
		return;
	}

	int i = 0;
	char **tmp = *p;
	for (i = 0; i < n; i++)
	{
		free(tmp[i]);
		tmp[i] = NULL;
	}
	if (tmp != NULL)
	{
		tmp = NULL;
		p = NULL;
	}
}


int main(void)
{
	int ret = 0;
	char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	char buf2[][30] = { "111111", "3333333", "222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = sizeof(buf2) / sizeof(buf2[0]);

	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("sort err: %d\n", ret);
		system("pause");
		return ret;
	}

	for (i = 0; i < len1 + len2; i++)
	{
		printf("%s\n", p3[i]);
	}

	free_malloc(&p3, (len1 + len2));


	printf("\n");
	system("pause");
	return 0;
}