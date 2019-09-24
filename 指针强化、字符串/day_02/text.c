#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	void *p = NULL;
	char buf[1024] = "aglsdjglkdsj";
	int a[100] = {1, 2, 3, 4};
	int i = 0;
	int b[3] = {1, 2, 3};
	int c[3];
    char str[] = "fdfsfssfsfs";
	char dst[100];
	char *q = NULL;
	char str2[100] = { 0 };
	p = buf;  //指向万能指正，要转化为实际类型指针
	printf("p = %s\n", p);
	
	p = a;
	for(i = 0; i < 4; i++)
	{
		printf("%d ",*((int*)p + i));
	}
	printf("\n");
	memcpy(c, b, sizeof(b));
	for(i = 0; i < 3; i++)
	{
		printf("%d ",c[i]);
	}

	
	printf("\n");

	memcpy(dst, str, sizeof(str));
	printf("dst = %s ", dst);
	printf("\n");

    
	q = str2;
	// 给q指向的内存空间赋值
	strcpy(q, "1234");  //此时的的q指针为野指针，因此执行strcpy（）时会出错。解决方法为添加上一行。

	printf("q = %s\n",q);

	printf("\n");
	system("pause");
	return 0;
}
				