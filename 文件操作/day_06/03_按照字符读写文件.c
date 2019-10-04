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


	fputc("a", stdout);   //stdout  指向屏幕

	char ch;
	ch = fgetc(stdin);  //stdin 指向键盘
	//fputc(ch, stdout);
	
	fprintf(stderr, "%c", ch); //stderr  指向屏幕， 错误信息


	printf("\n");
	system("pause");
	return 0;
}

int main02(void)
{
	FILE *fp = NULL;

    //C:\\Users\\阳可\Desktop\\C语言提高\\day_06\\day_06\\03test.txt      绝对路径
	//相对路径 ./    ../ 
	//vs:编译代码时，相对于项目工程(当前代码)
	//直接运行可执行程序，相对于程序
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
	fp = fopen(path, "w+");  //"w+"意思是若文件不存在则创建文件，若已存在则清空文件
	if (fp == NULL)
	{
		perror("my_fputc fopen error", stderr);
	}
	//写文件
	char buf[] = "this is a test for fputc";
	int i = 0;
	int n = strlen(buf);

	for (i = 0; i < n; i++)
	{
		fputc(buf[i], fp);  //fputc 返回值为成功写入的字符
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
	while (!feof(fp)) //文件没有结束
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