#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//argc:传参的个数（包括可执行程序）
//argv:指针数组，指向数去的参数
int main_01(int argc, char *argv[])
{
	//数组指针，指针数组
	
	//指针数组，他是数组，每个元素都是指针
	//[]比 *优先级高
	char *a[] = {"aaaaa", "bbbbb", "ccccc"};

	int i = 0;
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}


//定义数组指针方式一
int main_02(void)
{
	//数组指针，它是一个指针，指向一整个数组的指针
	//数组指针，指向一位数组的整个数组，而不是首元素
	//定义数组指针变量

	int i = 0;
	int a[10] = { 0 };
	//方式一：先定义数组类型，根据类型定义变量
	typedef int  A[10];  //A数组类型，[10]代表步长
	A *p = NULL; // p数组指针类型变量                          方式一
	//p = a; //a代表首元素地址，a 和 &a一样，最终也当做 &a，警告！
	p = &a; //a代表数组首地址

	for (i = 0; i < 10; i++)
	{
		//a[]
		//p = &a
		//*p = *&a -> a
		(*p)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*p)[i]); 
	}



	printf("\n");
	system("pause");
	return 0;
}


//定义数组指针方式二
int main_03(void)
{
	int i = 0;
	int a[10] = { 0 };
	//方式二：先定义数组指针类型，根据类型定义变量
	//和指针数组写法很类似，多了（）
	//（）和 [] 优先级一样，从左往右看
	//指针数组的指针，因为有typedef, 所以它 是一个数组指针类型
	typedef int (*P)[10];
	P q = NULL; //数组指针变量

	q = &a;
	for (i = 0; i < 10; i++)
	{
		(*q)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*q)[i]);
	}



	printf("\n");
	system("pause");
	return 0;
}

void fun(void *a)
{

}

//定义数组指针方式三
int main(void)
{
	int c = 10;
	fun((void *)&c);
	
	int i = 0;
	int a[10] = { 0 };
	//方式三：直接定义数组指针变量
	//和指针数组写法很类似，多了（）
	//（）和 [] 优先级一样，从左往右看
	//指针数组的指针，没有typedef, 所以它 是一个数组指针变量
	int(*q)[8];

	q = &a; //指向 a 数组
	for (i = 0; i < 10; i++)
	{
		(*q)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*q)[i]);
	}
	int b[1000] = { 0 };


	printf("\n");
	system("pause");
	return 0;
}