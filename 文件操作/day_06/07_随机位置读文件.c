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
	fp = fopen(path, "w+");  //"w+"意思是若文件不存在则创建文件，若已存在则清空文件
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

	//写文件,按块的方式写
	//s，写入文件内容的内存首地址
	//sizeof(Stu),块数据的大小
	//3, 块数。 写文件数据的大小sizeof(Stu) * 3
	//返回值。成功写入文件的块数目
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
	fp = fopen(path, "r+");  //"w+"意思是若文件不存在则创建文件，若已存在则清空文件
	if (fp == NULL)
	{
		perror("my_fread fopen error");
	}

	Stu st[3];
	Stu tmp; 
	int ret = 0;
	fseek(fp, 2 * sizeof(Stu), SEEK_SET);
	//fseek(fp, -1 * sizeof(Stu), SEEK_SET);
	ret = fread(&tmp, sizeof(Stu), 1, fp);
	if (ret == 1)
	{
		printf("tmp: %s, %d\n", tmp.name, tmp.id);
	}

	//把文件光标移动到最开始的地方
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);  //移动光标到最开始的地方

	//读文件,按块的方式写
	//s，放文件内容的首地址
	//sizeof(Stu),块数据的大小
	//3, 块数。 读文件数据的大小sizeof(Stu) * 3
	//返回值。成功读取文件的块数目
	 ret = fread(st, sizeof(Stu), 3, fp);
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("st[%d].name:%s\n", i, st[i].name);
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

	my_fwrite("../07.txt");
	my_fread("../07.txt");

	printf("\n");
	system("pause");
	return 0;
}