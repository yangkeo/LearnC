#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

				

int main(void)
{
	int *p = NULL;
	char **********q = NULL;
	int b = 0;
	int a = 100;
	int *p1 = NULL;

	printf("sizeof(p) = %d, sizeof(q) = %d\n", sizeof(p), sizeof(q));
	

	//ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ��˭
	p1 = &a;
	//*Կ�ף�ͨ��*�����ҵ�ָ��ָ����ڴ����򣬲��������ڴ�
	*p1 = 22;

	b = *p1;
	printf("b = %d, a = %d", b, a);


	printf("\n");
	system("pause");
	return 0;
	
}