#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void fun(char *p/* ����*/)
{
	//��pָ����ڴ����򿽱�
	strcpy(p, "sdfsfsdfs");
}

int fun2(char *p)
{
	if(p == NULL)
	{
		return 2;
	}
	strcpy(p, "werwer");
	return 0;	
}

void fun3(char **p/* out */, int *len)
{	
	char *tmp = NULL;
	printf("�ս�ȥfun3����p�ĵ�ַ = %d\n",p);
	if(p == NULL)
	{
		return;
	}
    tmp = (char *)malloc(100);

	strcpy(tmp ,"awmawmawmawmawmawm");
	//��Ӹ�ֵ
	printf("*p��û�ı�֮ǰ�ĵ�ַ = %d\n", *p);
	*p = tmp;
	printf("��fun3������\n");
	printf("*p��ַ = %d, p��ַ0 = %d, tmp��ַ = %d\n",*p, p, tmp);
	*len = strlen(tmp);
}



int main(void)                 
{
	//���룬�������������ڴ�
	char buf[100] = { 0 };
	char *str = NULL;
	char *p = NULL;
	int i = 2;
	int len = 0;

	fun(buf);  //ָ������������������ʱ�������������ڴ�

	printf("buf = %s\n", buf);

	fun2(str);  //��ӡ�������֤�������������ָ�����δ֪����ָ�븳ֵ
	printf("str = %s\n", str);
	
	i = fun2(str);
	printf("i = %d\n", i);

	//����������ú��������ڴ棬��ַ����
	printf("p��ַ = %d\n", &p);
	fun3(&p, &len);
	if(p != NULL)
	{
		printf("p = %s, len = %d\n", p, len);
		printf("p��ַ = %d\n", p);
	}

	
	printf("\n");
	system("pause");
	return 0;
}


 