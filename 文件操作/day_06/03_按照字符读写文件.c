#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main1(void)
{
	/*char buf[] = "this is a test";
	FILE *fp = fopen("./test.txt", "w+");

	fputs(buf, fp);
	fclose(fp);*/


	fputc("a", stdout);   //stdout  ָ����Ļ

	char ch;
	ch = fgetc(stdin);  //stdin ָ�����
	//fputc(ch, stdout);
	
	fprintf(stderr, "%c", ch); //stderr  ָ����Ļ�� ������Ϣ


	printf("\n");
	system("pause");
	return 0;
}

int main02(void)
{
	FILE *fp = NULL;

    //C:\\Users\\����\Desktop\\C�������\\day_06\\day_06\\03test.txt      ����·��
	//���·�� ./    ../ 
	//vs:�������ʱ���������Ŀ����(��ǰ����)
	//ֱ�����п�ִ�г�������ڳ���
	fp = fopen("./04.txt", "r+");

	if (fp == NULL)
	{
		perror("fopen");
		system("pause");
		return -1;
	}
	

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}

void my_fputc(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");  //"w+"��˼�����ļ��������򴴽��ļ������Ѵ���������ļ�
	if (fp == NULL)
	{
		perror("my_fputc fopen error", stderr);
	}
	//д�ļ�
	char buf[] = "this is a test for fputc";
	int i = 0;
	int n = strlen(buf);

	for (i = 0; i < n; i++)
	{
		fputc(buf[i], fp);  //fputc ����ֵΪ�ɹ�д����ַ�
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgetc(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "r+");
	char buf1[50];
	int i = 0;
	if (fp == NULL)
	{
		perror("my_fgetc fopen error");
	}
	char ch;
#if 0
	while ((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
	}
	printf("\n");
#endif
	while (!feof(fp)) //�ļ�û�н���
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

}

int main(void)
{
	
	//my_fputc("../03.txt");
	my_fgetc("../03.txt");
	

	printf("\n");
	system("pause");
	return 0;
}