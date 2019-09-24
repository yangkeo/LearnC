#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void my_strcpy(char *dst, char *src)
{
	int i = 0;
	for(i = 0; src[i] != 0; i++)
	{
		*(dst + i) = src[i]; //�Ⱥ���������ʵ�ʵȼ�
	}

	//��������
	dst[strlen(src)] = 0; //������ʽ:dst[i] = 0; *(dst + i) = 0;
}

void my_strcpy2(char *dst, char *src)
{
	int i = 0;
	while(*src != 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
}



void my_strcpy3(char *dst, char *src)
{
	while(*src != 0)
	{
		*dst++ = *src++;  //++��*���ȼ���ͬ���൱��������*dst = *src; dst++,src++;
	}
	*dst = 0;
}

void my_strcpy4(char *dst, char *src)
{
	//*dst = *src
	//dsr++ = src++
	while(*dst++ = *src++)
	{
	//	NULL;
	}
}

//����ͳ��strcpy����
char *my_strcpy5(char *dst, const char *src)
{
	char *ret = NULL;
	if((dst == NULL) || (src == NULL))
	{
		return NULL;
	}
	ret = dst;
	while((*dst = *src++) != 0);
	return ret;
}



int main()
{
    char src[] = "sdfdsafasf";
    char dst[100] = { 0 };
	my_strcpy5(dst, src);  //����ָ�뺯���Ƿ��ں�����ǰ��*δ֪
	printf("dst = %s\n", dst);

	printf("\n");
	system("pause");
	return 0; 
}

