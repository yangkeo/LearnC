#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"



int main01(char *p)   //��Ϊ�Լ���װ�ĺ���
{
	
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;


	//����߿�ʼ
	//�����ǰ�ַ�Ϊ�գ�����û�н���
	while(isspace(p[begin]) && p[begin] != 0)
	{
		begin++;  //λ�ô����ƶ�һλ
	}

	//�����ǰ�ַ�Ϊ�գ�����û�н���
	while(isspace(p[end]) && p[end] != 0)
	{
		end--; //λ�ô����ƶ�һλ
	}
	n = end - begin +1;
	return n;
}

int fun(char *p, int *n)  //��װ�ĺ���
{
	int begin = 0;
	int end = strlen(p) - 1;
	if(p == NULL || n == NULL)
	{
		return -1;
	}
	//����߿�ʼ
	//�����ǰ�ַ�Ϊ�գ�����û�н���
	while(isspace(p[begin]) && p[begin] != 0)
	{
		begin++;  //λ�ô����ƶ�һλ
	}

	//�����ǰ�ַ�Ϊ�գ�����û�н���
	while(isspace(p[end]) && p[end] != 0)
	{
		end--; //λ�ô����ƶ�һλ
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
	//����߿�ʼ
	//�����ǰ�ַ�Ϊ�գ�����û�н���
	while(isspace(p[begin]) && p[begin] != 0)
	{
		begin++;  //λ�ô����ƶ�һλ
	}

	//�����ǰ�ַ�Ϊ�գ�����û�н���
	while(isspace(p[end]) && p[end] != 0)
	{
		end--; //λ�ô����ƶ�һλ
	}
	n = end - begin +1;
	for(i = 0; i < n; i++)  ///////////////////////////////////////////////////////////
	{                       // ���򵥵ķ�ʽ                                          //
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


