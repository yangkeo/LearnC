#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

void my_fwrite(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");  //"w+"��˼�����ļ��������򴴽��ļ������Ѵ���������ļ�
	if (fp == NULL)
	{
		perror("my_fwrite fopen error");
	}
	
	Stu s[3];
	int i = 0;
	char buf[50];
	for (i = 0; i < 3; i++)
	{
		sprintf(buf, "lily%d%d", i, i);
		strcpy(s[i].name, buf);
		s[i].id = i + 1;
	}

	//д�ļ�,����ķ�ʽд
	//s��д���ļ����ݵ��ڴ��׵�ַ
	//sizeof(Stu),�����ݵĴ�С
	//3, ������ д�ļ����ݵĴ�Сsizeof(Stu) * 3
	//����ֵ���ɹ�д���ļ��Ŀ���Ŀ
	int ret = fwrite(s, sizeof(Stu), 3, fp);
	printf("ret = %d\n", ret);
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");  //"w+"��˼�����ļ��������򴴽��ļ������Ѵ���������ļ�
	if (fp == NULL)
	{
		perror("my_fread fopen error");
	}

	Stu st[3];
	int i = 0;
	//���ļ�,����ķ�ʽд
	//s�����ļ����ݵ��׵�ַ
	//sizeof(Stu),�����ݵĴ�С
	//3, ������ ���ļ����ݵĴ�Сsizeof(Stu) * 3
	//����ֵ���ɹ���ȡ�ļ��Ŀ���Ŀ
	int ret = fread(st, sizeof(Stu), 3, fp);

	for (i = 0; i < 3; i++)
	{
		printf("st[%d].name:%s\n", i, st[i].name );
		printf("st[%d].id:%d\n", i, st[i].id);
	}
	 
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{

	my_fwrite("../05.txt");
	my_fread("../05.txt");

	printf("\n");
	system("pause");
	return 0;
}