#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//�ַ����Ƚ�
int my_strcmp(const char *dst, const char *src)
{
	assert(dst != NULL && src != NULL);
	int ret = 0;
	while (!(ret = *(unsigned char *)dst - *(unsigned char *)src) && *dst)
	{
		dst++;
		src++;
	}
	if (ret > 0)
		return 1;
	else if (ret < 0)
		return -1;
	else
		return 0;
}

typedef struct Stu
{
	int num;
	char name[20];
}Stu;

//�ڴ濽��
void *my_memcpy(void *dst, const void *src, size_t count)
{
	assert(dst != NULL && src != NULL);
	char *dst1 = (char *)dst;
	char *src1 = (char *)src;
	for (int i = 0; i < count; i++)
		dst1[i] = src1[i];
	return dst;
}

//�ڴ濽���������ڴ��ص���
void *my_memmove(void *dst, void *src, size_t count)
{
	assert(dst != NULL && src != NULL);
	char *str_dst = (char *)dst;
	char *str_src = (char *)src;
	if (dst < src)
	{
		//ǰ�ص���ǰ���ص�����ǰ���
		for (int i = 0; i < count; i++)
			str_dst[i] = str_src[i];
	}
	else
	{
		//���ص�����ص����Ӻ���ǰ��
		for (int i = count - 1; i >= 0; i--)
			str_dst[i] = str_src[i];
	}
	return dst;
}

//���ַ����в���ָ���ַ�
char *strchr(const char *src, int character)
{
	assert(src != NULL);
	char *str_src = src;
	while (*str_src != character && *str_src != '\0')
		str_src++;
	if (*str_src == character)
		return str_src;
	else
		return NULL;	
}

//Դ�ַ������Ƿ����Ҫ���ҵ��ַ���
char *my_strstr(const char *haystack, const char *needle)
{
	assert(haystack, != NULL && needle != NULL);
	char *str1 = haystack;
	char *str2 = needle;
	if (*needle == 0)
		return NULL;
	while (*str1)
	{
		while (*str1 && *str2 && (*str1 == *str2))
		{
			str1++;
			str2++;
		}
		if (*str2 == 0)
			return haystack;
		else
		{
			str2 = needle;
			str1 = ++haystack;
		}
	}
	return NULL;
}

//�ַ�������
char* strcpy(char *dst, const char *src)
{
	assert(dst != NULL && src != NULL);
	char *ret = dst;
	while (*dst++ = *src++);
	return ret;
}

//�ַ���ƴ��
char* strcat(char *dst, const char *src)
{
	assert(dst != NULL && src != NULL);
	char *ret = dst;
	while (*dst)
		dst++;
	while (*dst++ = *src++);
	return ret;
}

int main(void)
{
	/*Stu s1 = { 20, "xiaoming" };
	Stu s2;*/
	/*int arr[10] = { 1, 2, 3, 4, 5 };
	my_memmove(&arr[3], arr, sizeof(int) * 5);*/

	char *str = "012345678";
	char *ret = strchr(str, '9');

	printf("\n");
	system("pause");
	return 0;
}

