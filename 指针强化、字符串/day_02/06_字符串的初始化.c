#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main_01(void);

/*
c语言没有字符串类型，通过字符数据模拟
c语言字符串，以‘\0’，数字0

*/
int main_01(void)                 
{
	//不指定长度,没有0结束符，打印结果会有乱码
	char buf[] = {'a', 'b', 'c'};
	char buf1[100] = {'a', 'b', 'c'};
	char buf5[50] = {'1', 'a', 'b', '0', '7'};
	char buf6[50] = {'1', 'a', 'b', 0, '7'};//结果只有0ab
	char buf7[50] = {'1', 'a', 'b', '\0', '7'};//结果也只有0ab
	//使用字符串初始化，最常用！！
	char buf8[] = "dfjosijfosijfojf";
	char buf9[100] = "dfjosijfosijfojf";
	printf("buf = %s\n",buf);

	//指定长度，后面没有复制的元素，自动补0
	printf("buf = %s\n",buf1);

	/*
	char buf2[100] = { 0 };  //所有元素赋值为0
	char buf3[2] = {'1', '2', '3'};//数组越界
	*/
	
	printf("buf5 = %s\n", buf5);
	printf("buf6 = %s\n", buf6);
	printf("buf7 = %s\n", buf7);
	//strlen:测字符串长度，不包括数字0，字符'\0'
	//sizeof:测数组长度，包括数字0，字符'\0'
	printf("strlen = %d, sizeof = %d\n", strlen(buf8), sizeof(buf8));
	printf("strlen = %d, sizeof = %d\n", strlen(buf9), sizeof(buf9));
	printf("\n"); 
	system("pause");
	return 0;
}

int main()
{
	int i;	
	char buf[] = "dfsadggdfveargvdfv";
	int n = strlen(buf);
	char *p = NULL;


	//[]方式
	for(i = 0; i < n; i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	//指针方法
	//数组名字是数组首元素地址

	p = buf;
	for(i = 0; i < n; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	for(i = 0; i < n; i++)
	{
		printf("%c",*( p+i));
	}
	printf("\n");

	for(i = 0; i < n; i++)
	{
		printf("%c",*(buf+i));
	}
	printf("\n");

	//buf和p完全等价吗？
	//p++;
	//buf++;
	//buf只是一个常量，不能修改，所以不能buf++(buf++是在修改buf本身的值),但buf+i是允许的


 
	printf("\n");
	system("pause");
	return 0;
}







 