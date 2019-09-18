#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main01(void)
{
	//a代表首行地址，首行地址和首元素地址有区别，但是值是一样的
	//区别：步长不一样   首行地址加1跳30个字节；首元素地址加1跳1个字节
	
	/*
	printf("%d    %d\n", a, a + 1);   //加30
	printf("%d    %d\n", a, &a + 1);  //加120
	printf("%d    %d\n", a, *(a + 1)); //加30

	char b[30] = {"11111111111"};
	printf("%d   %d\n", b, b + 1);  //加1
	printf("%d   %d\n", b, &b + 1);  //加30
	*/

}

void printf_array_err(char *p, int n) //弄不成
{
	//printf("a:  %d a+1:   %d\n", p, p + 1);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s, \n", p + i);
	}
	printf("\n");
}

void printf_array(char a[][30], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", a + i);
	}
}

void sort_array(char a[][30], int n)
{
	int i = 0;
	int j = 0;
	char tmp[30];

	for (i = 0; i < n - 1; i++)
	{
		for (j = i +1; j < n; j++)
		{
			if (strcmp(a[i], a[j]) > 0)
			{
				//交换的是内存块，不是指针的指向
				strcpy(tmp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], tmp);
				//tmp[30] = a[i];
				//a[i] = a[j];       弄不成
				//a[j] = tmp[30];
			}
		}
	}
}

void main(void)
{
	//a代表首行地址，首行地址和首元素地址有区别，但是值是一样的
	//区别：步长不一样   首行地址加1跳30个字节；首元素地址加1跳1个字节
	char a[4][30] = { "1111111", "4444444", "3333333", "2222222" };
	int n = sizeof(a) / sizeof(a[0]);


	//printf("a:  %d a+1:   %d\n", a, a + 1);
	printf("before sort:\n");
	printf_array(a, n);

	sort_array(a, n);

	printf("after sort:\n");
	printf_array(a, n);

	printf("\n");
	system("pause");
	return 0;
}

