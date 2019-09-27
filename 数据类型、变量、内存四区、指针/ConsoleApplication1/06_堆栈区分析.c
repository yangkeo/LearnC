#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

char *get_str()
{
	int i = 0;
	char str[] = "abcdefgh";  //栈区
	  printf("str[] = %s\n", str);
	return str;  //返回的首地址(看函数名中的*)
}

char *get_str2()
{
	char *tmp = (char *)malloc(100);
	if(tmp == NULL)
	{
		return NULL;
	}
	strcpy(tmp, "abcdefghi");
	return tmp;
}


int main(void)
{
	int i = 0;
	char buf[128] = { 0 };
	//strcpy(buf, get_str());  	
   	//printf("buf = %s\n",buf);  //！！！有可能是a~h‘有可能乱码。因为get_str()返回给buf的是str的首地址，当get_str()执行完毕后栈区会将空间释放str[]中的内容可能改变
	char *p;
	p = get_str2();
	if(p != NULL)
	{
		printf("p = %s\n", p);
		free(p);
		p = NULL;
	}

	
	
	printf("\n");
	system("pause");
	return 0;
	
}