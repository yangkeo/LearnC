#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main01(void)
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	//+16
	//二维数组数组名代表第0行的首地址 （区别于第0行首元素地址，虽然值一样）
	//它们步长不一样
	printf("a:%d, a+1:%d\n", a2, a2 + 1); 
	printf("%d  %d\n", *(a2 + 0), *(a2 + 0) + 1); //第0行首元素地址  和第0行第二个元素地址
	printf("%d  %d\n",a2[0], a2[0] + 1);  //与上一行等价，，对于上一行的 * 就相当于这一行的 []

	//int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//a 代表数组第0行首地址
	//a + i -> &a[i]:代表第i行首地址
	//*(a+i) -> a[i]代表第i行首元素的地址
	//*(a+i)+j -> &a[i][j] = 代表第i行第j列元素的地址
	//*((a+i)+j) -> a[i][j] = 第i行第j列元素的值





	printf("\n");
	system("pause");
	return 0;
}


void printA(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}


int main02(void)
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	
	printA((int *)a, sizeof(a) / sizeof(a[0][0]));


	printf("\n");
	system("pause");
	return 0;
}


int main03(void)
{
	int a[3][10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//3个a[4]的一位数组

#if 0
	//定义一个数组指针变量
	int (*p)[10];
	p = a; //第0行首地址，p等价于二维数组名
	printf("p:%d, p+1:%d\n", p, p + 1); //10 * 4 = 40

#endif

	//定义数组指针类型，再定义变量
	typedef int(*P)[10];
	P p;
	p = a;



	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			//printf("%d ", p[i][j]);
			printf("%d ", *(*(p + i) + j)); //与上一行等价
		}
		printf("\n");
	}

	//测一位数组长度的时候，sizeof()首行首元素地址
	char t[10];
	printf("sizeof(t):%d, sizeof(&t):%d\n", sizeof(t), sizeof(&t));

	//int a[3][10]
	printf("sizeof(a[0]):%d, sizeof(&a[0]):%d\n", sizeof(a[0]), sizeof(&a[0]));


	printf("\n");
	system("pause");
	return 0;
}


void printArray(int a[3][4]) //5k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

//数组形参都会退化为指针，指针步长不一定一样
void printArray01(int a[][4]) //7k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


//用数组指针
void printArray02(int (*p)[4]) //9k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", p[i][j]);   //与上一行等价
		}
		printf("\n");
	}
}


//用数组指针

typedef int(*Q)[4];
void printArray03(Q p) //9k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", p[i][j]);   //与上一行等价
		}
		printf("\n");
	}
}

int main(void)
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printArray03(a);


	printf("\n");
	system("pause");
	return 0;
}