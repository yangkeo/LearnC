#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMen(char *p)
{
	p = (char *)malloc(sizeof(char)* 100);
	if (p == NULL)
	{
	return -1;
	}

	strcpy(p, "sdfsfsd");
	printf("p1 = %s\n", p);


	return 0;
}

int getMen2(char **p)
{
	if (p == NULL)
	{
		return -2;
	}

	char *tmp = (char *)malloc(sizeof(char)* 100);
	if (tmp == NULL)
	{
		return -2;
	}

	strcpy(tmp, "yangke");

	*p = tmp;

	return 0;
}


int main(void)
{
	char *p = NULL;
	int ret = 0;

	ret = getMen2(&p);  //调用时，main函数中指针p的指向一直没变，调用完后p指向内存的数据发生变化
	if (ret != 0)
	{
		printf("getMen  err: %d\n", ret);
		return ret;
	}

	printf("p = %s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	printf("\n");
	system("pause");
	return 0;
}