#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,ssss,����

д��������(API)��������½��
��һ��API(�ڶ����ڴ�ģ�ͣ� ��ά����)
1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
2)�Ѷ�ά��������������Ҳ����
int spitString(const char *str, char c, char buf[10][30], int *count);

/*�ڶ���API(�������ڴ�ģ�ͣ���̬���ɶ�ά�ڴ�)
1)�Զ��ŷָ��ַ������γ�һ������ָ�롣
2)��һ����ֶ������ַ�����������
int spitString2(const char *str, char c, char **myp , int *count);
/*
Ҫ��
1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
2, ��ȷʵ�ֽӿں͹���.
3, ��д��ȷ�Ĳ�������.
*/

int spitString(const char *str, char c, char buf[10][30]/*in*/, int *count)
{
	if (str == NULL || count == NULL)
	{
		return -1;
	}
	const *start = str;
	char *p = NULL;
	int i = 0;
	do
	{
		p = strstr(start, ",");
		if (p != NULL)
		{
			strncat(buf[i], start, (p - start));
			start = p + 1;
			i++;
		}
		else
		{
			strcat(buf[i], start);
			i++;
			break;
		}
		
	} while (*start != 0);
	*count = i;
	/*for (i = 0; i < 6; i++)
	{
		printf("%s\n", buf[i]);
	}
	char **q = NULL;
	int len = sizeof(buf) / sizeof(buf[0]);
	for (i = 0; i < len; i++)
	{
		q[i] = (char *)malloc(sizeof(100));
	}*/
	
	return 0;
}

int spitString2(const char *str, char c, char **myp /*in*/, int *count)
{

}



int main(void)
{
	const char *p = "abcdef, acccd, eeee, aaaa, e3eeee, ssss,";
	char buf[10][30] = { 0 };
	int n = 0, ret = 0;

	ret = spitString(p, ',', buf, &n);
	if (ret != 0)
	{
		printf("spitString err: %d", ret);
		system("pause");
		return ret;
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}
	printf("n = %d", n);
	
	printf("\n");
	system("pause");
	return 0;
}


//int main_1(void)
//{
//	const char *p = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
//	char **buf = NULL;
//	int n = 0, ret = 0;
//
//	buf = getMem(6);
//	if (ret != 0)
//	{
//		printf("spitString err: %d", ret);
//		system("pause");
//		return ret;
//	}
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%s\n", buf[i]);
//	}
//	printf("n = %d", n);
//
//	printf("\n");
//	system("pause");
//	return 0;
//}
