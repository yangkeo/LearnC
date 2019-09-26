#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[50];
	int age;
}Teacher;


int main(void)
{
	Teacher a[3] = { { "a", 18 }, { "a", 18 }, { "a", 18 } };

	//静态
	Teacher a2[3] = { "a", 18, "a", 18, "a", 18 };

	//动态数组
	int b[3] = { 0 };
	int *pB = (int)malloc(3 * sizeof(int));
	free(pB);

	//动态结构体数组
	Teacher *p = (Teacher *)malloc(3 * sizeof(Teacher));
	if (p == NULL)
	{
		return -1;
	}
	int i = 0;
	char buf[50] = { 0 };
	for (i = 0; i < 3; i++)
	{
		sprintf(buf, "name%d%d%d", i, i, i);
		strcpy(p[i].name, buf);
		p[i].age = 20 + i;
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s, %d", p[i].name, p[i].age);
	}


	printf("\n");
	system("pause");
	return 0;
}