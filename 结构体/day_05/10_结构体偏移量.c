#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ṹ������ȷ���������ڲ��ĳ�Ա�������ڴ沼���Ѿ�ȷ��
typedef struct Teacher
{
	char name[64];  //64
	int age;  //4
	int id; //4
}Teacher;


int main(void)
{
	Teacher t1;
	Teacher *p = NULL;
	p = &t1;
	
	int n1 = (int)(&p->age) - (int)p;  //->���ȼ���&  //����ڽṹ���׵�ַ
	printf("n1 = %d\n", n1);

	int n2 = (int)&((Teacher *)0)->age;  //����ڽṹ���ڲ�0��ַ�ľ���ƫ����
	printf("n2 = %d\n", n2);

	printf("\n");
	system("pause");
	return 0;
}