#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void my_fputs(char *path)
{
	FILE *fp = NULL;
	fp = fopen(path, "w+");  //"w+"意思是若文件不存在则创建文件，若已存在则清空文件
	if (fp == NULL)
	{
		perror("my_fputc fopen error", stderr);
	}
	//写文件
	char *buf[] = { "aaaaaaa\n", "bbbbbbb\n", "ccccccc\n"};
	int i = 0;
	int n = 3;

	for (i = 0; i < n; i++)
	{
		fputs(buf[i], fp); //返回值， 成功为0，不成功非0 
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

	while (!feof(fp)) //文件没有结束
	{
		//sizeof(buf),最大值，放不下了，就只能放sizeof（buf），不超过就实际大小存放
		//返回值为成功读取的文件内容
		//“\n”会读取，以“\n”作为换行的标志
		//fgets()读取完后，会自动加几结束符
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