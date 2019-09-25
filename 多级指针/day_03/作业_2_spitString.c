#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,ssss,”）

写两个函数(API)，输出以下结果
第一个API(第二种内存模型： 二维数组)
1)以逗号分隔字符串，形成二维数组，并把结果传出
2)把二维数组行数运算结果也传出
int spitString(const char *str, char c, char buf[10][30], int *count);

/*第二个API(第三种内存模型：动态生成二维内存)
1)以逗号分隔字符串，形成一个二级指针。
2)把一共拆分多少行字符串个数传出
int spitString2(const char *str, char c, char **myp , int *count);
/*
要求：
1, 能正确表达功能的要求，定义出接口。
2, 正确实现接口和功能.
3, 编写正确的测试用例.
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
