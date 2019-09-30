#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int main(void)
{
	int a;  //告诉编译器，分配4个字节
	int b[10];  //分配4*10个字节
	/*
	类型的本质：固定内存块大小别名
	可通过sizeof（）测试
	*/
	
	printf("sizeof(a)= %d, sizeof(b)= %d\n", sizeof(a), sizeof(b));

	//打印地址
	//数组名就是数组首元素的地址
	printf("b:%d，&b:%d\n", b, &b);
	//b,&b的数据类型不一样
	//b,数组首元素地址 
	//&b,整个数组的首地址，一个数组4*10=40字节，+1， +40
	printf("b+1:%d，&b+1:%d\n", b+1, &b+1);

	//指针类型长度，32位程序，长度4
	//              64位程序，长度8
	char *******************p= NULL;
	int *q= NULL;
	printf("%d,%d\n",sizeof(p), sizeof(q));

	printf("\n");
	system("pause");
	return 0;
	
}