#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//字符串比较
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

//内存拷贝
void *my_memcpy(void *dst, const void *src, size_t count)
{
	assert(dst != NULL && src != NULL);
	char *dst1 = (char *)dst;
	char *src1 = (char *)src;
	for (int i = 0; i < count; i++)
		dst1[i] = src1[i];
	return dst;
}

//内存拷贝（避免内存重叠）
void *my_memmove(void *dst, void *src, size_t count)
{
	assert(dst != NULL && src != NULL);
	char *str_dst = (char *)dst;
	char *str_src = (char *)src;
	if (dst < src)
	{
		//前重叠或前不重叠，从前向后拷
		for (int i = 0; i < count; i++)
			str_dst[i] = str_src[i];
	}
	else
	{
		//后重叠或后不重叠，从后往前拷
		for (int i = count - 1; i >= 0; i--)
			str_dst[i] = str_src[i];
	}
	return dst;
}

//在字符串中查找指定字符
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

//源字符串中是否包含要查找的字符串
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

//字符串拷贝
char* strcpy(char *dst, const char *src)
{
	assert(dst != NULL && src != NULL);
	char *ret = dst;
	while (*dst++ = *src++);
	return ret;
}

//字符串拼接
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

