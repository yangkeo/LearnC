#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"



int main01(char *p)   //此为自己封装的函数
{
	
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;


	//从左边开始
	//如果当前字符为空，而且没有结束
	while(isspace(p[begin]) && p[begin] != 0)
	{
		begin++;  //位置从右移动一位
	}

	//如果当前字符为空，而且没有结束
	while(isspace(p[end]) && p[end] != 0)
	{
		end--; //位置从左移动一位
	}
	n = end - begin +1;
	return n;
}

int fun(char *p, int *n)  //封装的函数
{
	int begin = 0;
	int end = strlen(p) - 1;
	if(p == NULL || n == NULL)
	{
		return -1;
	}
	//从左边开始
	//如果当前字符为空，而且没有结束
	while(isspace(p[begin]) && p[begin] != 0)
	{
		begin++;  //位置从右移动一位
	}

	//如果当前字符为空，而且没有结束
	while(isspace(p[end]) && p[end] != 0)
	{
		end--; //位置从左移动一位
	}
	*n = end - begin +1;
	return 0;
}

int fun02(char *p, char *buf)
{
	int i = 0;
	int n = 0;
	int begin = 0;
	int end = strlen(p) - 1;
	if(p == NULL || buf == NULL)
	{
		return -1;
	}
	//从左边开始
	//如果当前字符为空，而且没有结束
	while(isspace(p[begin]) && p[begin] != 0)
	{
		begin++;  //位置从右移动一位
	}

	//如果当前字符为空，而且没有结束
	while(isspace(p[end]) && p[end] != 0)
	{
		end--; //位置从左移动一位
	}
	n = end - begin +1;
	for(i = 0; i < n; i++)  ///////////////////////////////////////////////////////////
	{                       // 更简单的方式                                          //
		buf[i] = p[begin];  // strcpy(buf, p + begin, n);                            // 
		begin++;            //                                                       //
	}	                    ///////////////////////////////////////////////////////////
	return 0;
}


int main()
{
	char *p = "      abcdefgrthrrttrtrth     ";
	int n = 0;
	int ret = 0;


	/*ret = fun(p, &n);
	if(ret != 0)
	{
		return ret;
	}

	printf("n = %d\n", n);*/
	char buf[100] = { 0 };
	fun02(p, buf);
	printf("buf = %s\n", buf);

	printf("\n");
	system("pause");
	return 0; 
}


