#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int a;
	int b;
}Mystruct;

void fun(Mystruct *p)
{
	//指针能变
	//指针指向内存也可变
	//p->a = 10;  //(*p).a = 10;
	//p = NULL;//OK

	
}

void fun1(Mystruct  const *p)
{
	//p = NULL;//OK
	//p->a = 12; //err
}

void fun2(Mystruct * const p)
{
	//p = NULL;//err
	//p->a = 4;//ok
}

void fun3(Mystruct const * const p)   //p只读 
{
	Mystruct tmp;
	tmp.a = p->a;
}

int main(void)
{
	//const修饰一个变量为只读
	const int a = 10;
	char buf[] = "sfsdfsdfsdf";

	//从左往右看，跳过类型，看修饰那个字符
	//如果是*，说明指针指向的内存不能变
	//如果是指针变量，说明指针的指向不能变，即指针的值不能变
	const char *p = buf;
	// 等价上面char const *p1 = buf;
	//对于上面两种情况，p[1] = '2';//err, 不能通过p[]来修改内存的值，但可buf[]改变
	//p = "sdkjbfksfkjsd"//ok 即p的指向可以改变


	char * const p2 = buf;
	//p2[1] = '2';// ok
	//p2 = "sssssdfs"// err

	const char * const p3 = buf;  //完全只读



	printf("\n");
	system("pause");
	return 0;
}