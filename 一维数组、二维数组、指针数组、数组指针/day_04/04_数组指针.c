#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//argc:���εĸ�����������ִ�г���
//argv:ָ�����飬ָ����ȥ�Ĳ���
int main_01(int argc, char *argv[])
{
	//����ָ�룬ָ������
	
	//ָ�����飬�������飬ÿ��Ԫ�ض���ָ��
	//[]�� *���ȼ���
	char *a[] = {"aaaaa", "bbbbb", "ccccc"};

	int i = 0;
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}


//��������ָ�뷽ʽһ
int main_02(void)
{
	//����ָ�룬����һ��ָ�룬ָ��һ���������ָ��
	//����ָ�룬ָ��һλ������������飬��������Ԫ��
	//��������ָ�����

	int i = 0;
	int a[10] = { 0 };
	//��ʽһ���ȶ����������ͣ��������Ͷ������
	typedef int  A[10];  //A�������ͣ�[10]������
	A *p = NULL; // p����ָ�����ͱ���                          ��ʽһ
	//p = a; //a������Ԫ�ص�ַ��a �� &aһ��������Ҳ���� &a�����棡
	p = &a; //a���������׵�ַ

	for (i = 0; i < 10; i++)
	{
		//a[]
		//p = &a
		//*p = *&a -> a
		(*p)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*p)[i]); 
	}



	printf("\n");
	system("pause");
	return 0;
}


//��������ָ�뷽ʽ��
int main_03(void)
{
	int i = 0;
	int a[10] = { 0 };
	//��ʽ�����ȶ�������ָ�����ͣ��������Ͷ������
	//��ָ������д�������ƣ����ˣ���
	//������ [] ���ȼ�һ�����������ҿ�
	//ָ�������ָ�룬��Ϊ��typedef, ������ ��һ������ָ������
	typedef int (*P)[10];
	P q = NULL; //����ָ�����

	q = &a;
	for (i = 0; i < 10; i++)
	{
		(*q)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*q)[i]);
	}



	printf("\n");
	system("pause");
	return 0;
}

void fun(void *a)
{

}

//��������ָ�뷽ʽ��
int main(void)
{
	int c = 10;
	fun((void *)&c);
	
	int i = 0;
	int a[10] = { 0 };
	//��ʽ����ֱ�Ӷ�������ָ�����
	//��ָ������д�������ƣ����ˣ���
	//������ [] ���ȼ�һ�����������ҿ�
	//ָ�������ָ�룬û��typedef, ������ ��һ������ָ�����
	int(*q)[8];

	q = &a; //ָ�� a ����
	for (i = 0; i < 10; i++)
	{
		(*q)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", (*q)[i]);
	}
	int b[1000] = { 0 };


	printf("\n");
	system("pause");
	return 0;
}