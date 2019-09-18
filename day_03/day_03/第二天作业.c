#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3. ��һ���ַ�����1a2b3d4z����
Ҫ��дһ������ʵ�����¹��ܣ�
����1����ż��λ�ַ���ѡ���������һ���ַ���1��
����2��������λ�ַ���ѡ���������һ���ַ���2��
����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
����4���������ܲ���ͨ����
int getStr1Str2(char *source, char *buf1, char *buf2);

*/

int getStr1Str2(char *source, char *buf1/*int */, char *buf2)
{
	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		return -1;
	}

	int n = strlen(source); //�ַ�������
	int i = 0;

	for (i = 0; i < n; i++)
	{
		//���������λ
		if ((i % 2) != 0)
		{
			*buf1 = *(source + i); //  ͬ��source[i]
			buf1++;
		}
		else//�����ż��λ
		{
			*buf2 = source[i]; //   *(source + i)
			buf2++;
		}

	}

	//û�н�����
	*buf1 = 0;
	*buf2 = 0;

	return 0;
}
int main(void)
{
	char *p = "1a2b3d4z";
	char buf1[50] = { 0 };
	char buf2[50] = { 0 };
	int ret = 0;

	ret = getStr1Str2(p, buf1, buf2);
	if (ret != 0)
	{
		printf("getStr1Str2 err:%d\n", ret);
		return ret;
	}

	printf("buf1 = %s\n", buf1);
	printf("buf2  = %s\n", buf2);


	printf("\n");
	system("pause");
	return 0;
}