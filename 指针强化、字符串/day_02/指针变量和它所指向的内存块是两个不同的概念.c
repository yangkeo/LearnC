#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	char *p = NULL;
	char buf[] = "abcdef";
	char *buf2 = "aaasssddd";
	char buf3[] = "sfdsfsfsdf";
	char *p2 = NULL;
	p = buf;
	printf("p2 = %s\n", p);
	//printf("p1地址 = %d", p);

	//指针变量和指向的内存块是两个不同的概念
	p = p + 1; //改变了指向变量的值，改变了指针的指向

	//printf("p2地址 = %d", p);
	printf("%s\n", p);
	//写内存时，一定要确保内存可写
	buf2[2] = '1';  //error  此时的aaasssddd存在于文字常量区，不能修改（内存不可改）
	//然而
	buf3[1] = '1'; //是ok的
	p2 = buf3;
	strcpy(p2,"rgrgrgrgr"); //error  不允许向NULL和非法地址拷贝内存
	printf("buf3 = %s\n", p2);
	printf("\n");
	system("pause");
	return 0;
}
				