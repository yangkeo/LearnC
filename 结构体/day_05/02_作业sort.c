#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
功能：1、把数组p1的字符串取出来
      2、把二维数组buf2的字符取出来
	  3、上面的字符串放在p3, p3是在堆区分配的二维内存
	  4、对p3中字符串进行排序，通过 strcmp()进行排序
参数：
     p1：指针数组首地址，char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	 len1：p1元素个数
	 buf2：二维数组首元素地址，buf2[10][30] = { "111111", "3333333", "222222" };
	 len2: buf2字符串行数
	 p3：二级指针的地址，需要再函数内分配二维内存，保存p1和buf2的字符串，还需要排序
	 len3：保存p3中字符串个数
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

	//给每个指针分配内存（指向堆区）
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
				strcpy(tmp[i], tmp[j]);    //err: 这种交换方式是值交换，因为内存块大小不一所以会出错
				strcpy(tmp[j], p);*/
				//指针指向交换
				p = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = p;
			}
		}
	}

	//间接赋值是指针存在最大意义
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