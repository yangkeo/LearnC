#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int get_a()
{
	int a = 10;
	return a;
}

int get_a2(int b)
{
	b = 22;
	return b;
}

void get_a3(int *p)
{
	*p = 33;
	
}

void get_a4(int *a, int *b, int *c, int *d)
{
	*a = 1;
	*b = 2;
	*c = 3;
	*d = 4;	
}



int main_01()
{
	int a = 100;
	int b = 0;
	int a1, a2, a3, a4;
	int *p = NULL;

	//建立关系，指针指向谁，就把谁的地址赋值
	p = &a;  //通过*操作内存

	*p = 22;
	/*通过指针间接赋值
	1.两个变量
	2.建立关系
	3.通过*操作内存
	*/

    b = get_a();
	printf("b = %d\n", b);

	get_a2(b);
	printf("b2 = %d\n", b); //b的值为10，不是22.main中的b和get_a2()中b是不同的。

	//如果想通过形参改变实参的内存内容（值），则必须地址传递
    //实参，形参
	get_a3(&b); //在函数调用时，建立关系
	printf("b3 = %d\n", b);

	get_a4(&a1, &a2, &a3, &a4);
	printf("a1 = %d, a2 = %d, a3 = %d, a4 = %d", a1, a2, a3, a4);

	printf("\n");
	system("pause");
	return 0;
}

void fun2(int *p)
{
	p = (int *)0xaabb;
    printf("fun2: = %p\n", p);
}

void fun3(int **p)
{
	*p = (int *)0xddff;
	printf("fun3 = %p\n", *p);
}


int main(void)
{
	//一个变量，应该定义一个怎样类型的指针保存它的地址
	//就是在原来类型基础上多加一个*
	//int a = 10;
	//int *p = &a;
	//int **q = &p;
	//printf("p地址 = %d, q指向 = %d\n", p,9 *q);
	
	/*比如
	int *********t = NULL;
	int **********t1 = &t;
	*/
	int *p = (int *)0x1122;
	printf("p1 = %p\n", p);

	fun2(p);  //值传递
	printf("p1 = %p\n\n", p);

	fun3(&p);//地址传递（归根到底还是值的传递）
	printf("p1 = %p\n", p);


	printf("\n");
	system("pause");
	return 0;
}


 