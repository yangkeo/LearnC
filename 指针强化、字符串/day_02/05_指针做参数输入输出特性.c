#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void fun(char *p/* 输入*/)
{
	//给p指向的内存区域拷贝
	strcpy(p, "sdfsfsdfs");
}

int fun2(char *p)
{
	if(p == NULL)
	{
		return 2;
	}
	strcpy(p, "werwer");
	return 0;	
}

void fun3(char **p/* out */, int *len)
{	
	char *tmp = NULL;
	printf("刚进去fun3函数p的地址 = %d\n",p);
	if(p == NULL)
	{
		return;
	}
    tmp = (char *)malloc(100);

	strcpy(tmp ,"awmawmawmawmawmawm");
	//间接赋值
	printf("*p在没改变之前的地址 = %d\n", *p);
	*p = tmp;
	printf("在fun3函数中\n");
	printf("*p地址 = %d, p地址0 = %d, tmp地址 = %d\n",*p, p, tmp);
	*len = strlen(tmp);
}



int main(void)                 
{
	//输入，主调函数分配内存
	char buf[100] = { 0 };
	char *str = NULL;
	char *p = NULL;
	int i = 2;
	int len = 0;

	fun(buf);  //指针做函数参数，输入时主调函数分配内存

	printf("buf = %s\n", buf);

	fun2(str);  //打印结果可以证明，不可以向空指针或者未知区域指针赋值
	printf("str = %s\n", str);
	
	i = fun2(str);
	printf("i = %d\n", i);

	//输出，被调用函数分配内存，地址传递
	printf("p地址 = %d\n", &p);
	fun3(&p, &len);
	if(p != NULL)
	{
		printf("p = %s, len = %d\n", p, len);
		printf("p地址 = %d\n", p);
	}

	
	printf("\n");
	system("pause");
	return 0;
}


 