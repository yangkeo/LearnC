#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void my_fputs(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");  //"w+"��˼�����ļ��������򴴽��ļ������Ѵ���������ļ�
	if (fp == NULL)
	{
		perror("my_fputc fopen error", stderr);
	}
	//д�ļ�
	char *buf[] = { "aaaaaaa\n", "bbbbbbb\n", "ccccccc\n"};
	int i = 0;
	int n = 3;

	for (i = 0; i < n; i++)
	{
		fputs(buf[i], fp); //����ֵ�� �ɹ�Ϊ0�����ɹ���0 
	}
	
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgets(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");
	int i = 0;
	if (fp == NULL)
	{
		perror("my_fgetc fopen error");
	}
	char buf[100] = { 0 };

	while (!feof(fp)) //�ļ�û�н���
	{
		//sizeof(buf),���ֵ���Ų����ˣ���ֻ�ܷ�sizeof��buf������������ʵ�ʴ�С���
		//����ֵΪ�ɹ���ȡ���ļ�����
		//��\n�����ȡ���ԡ�\n����Ϊ���еı�־
		//fgets()��ȡ��󣬻��Զ��Ӽ�������
		char *p = fgets(buf, sizeof(buf), fp);
		if (p != NULL)
		{
			printf("buf = %s\n", buf);
			printf("%s\n", p);
		}		
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

}

int main(void)
{

	my_fputs("../04.txt");
	my_fgets("../04.txt");

	printf("\n");
	system("pause");
	return 0;
}