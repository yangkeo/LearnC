#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int a;
	int b;
}Mystruct;

void fun(Mystruct *p)
{
	//ָ���ܱ�
	//ָ��ָ���ڴ�Ҳ�ɱ�
	//p->a = 10;  //(*p).a = 10;
	//p = NULL;//OK

	
}

void fun1(Mystruct  const *p)
{
	//p = NULL;//OK
	//p->a = 12; //err
}

void fun2(Mystruct * const p)
{
	//p = NULL;//err
	//p->a = 4;//ok
}

void fun3(Mystruct const * const p)   //pֻ�� 
{
	Mystruct tmp;
	tmp.a = p->a;
}

int main(void)
{
	//const����һ������Ϊֻ��
	const int a = 10;
	char buf[] = "sfsdfsdfsdf";

	//�������ҿ����������ͣ��������Ǹ��ַ�
	//�����*��˵��ָ��ָ����ڴ治�ܱ�
	//�����ָ�������˵��ָ���ָ���ܱ䣬��ָ���ֵ���ܱ�
	const char *p = buf;
	// �ȼ�����char const *p1 = buf;
	//�����������������p[1] = '2';//err, ����ͨ��p[]���޸��ڴ��ֵ������buf[]�ı�
	//p = "sdkjbfksfkjsd"//ok ��p��ָ����Ըı�


	char * const p2 = buf;
	//p2[1] = '2';// ok
	//p2 = "sssssdfs"// err

	const char * const p3 = buf;  //��ȫֻ��



	printf("\n");
	system("pause");
	return 0;
}