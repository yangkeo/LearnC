#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//��ʽһ
void leftRotate(char* str, int k)
{
	while (k--)
	{
		char *arr = str;
		char tmp = *arr;
		while (*(arr + 1) != 0)
		{
			*arr = *(arr + 1);
			arr++;
		}
		*arr = tmp;
	}	
}

//��ʽ��
void ReverseStr(char *str, int len)
{
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

void leftRotate2(char* str, int k)
{
	int len = strlen(str);
	ReverseStr(str, k);
	ReverseStr(str + k, len - k);
	ReverseStr(str, len);
}

//int main(void)
//{
//	char str[] = "ABCD";
//	int k = 0;
//	scanf("%d", &k);
//	leftRotate2(str, k);
//	printf("%s\n", str);
//	printf("\n");
//	system("pause");
//	return 0;
//}

int main(void)
{
	char src[] = "AABCD";
	char dest[] = "CDAAB";
	int len = strlen(src);
	for (int i = 1; i <= len; i++)
	{
		leftRotate2(src, 1);
		if (strcmp(src, dest) == 0)
		{
			printf("dest��src����%d��������Ľ��\n", i);
			break;
		}
	}	

	printf("\n");
	system("pause");
	return 0;
}