#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int get_a()
{
	int a = 10;
	return a;
}

int get_a2(int b)
{
	b = 22;
	return b;
}

void get_a3(int *p)
{
	*p = 33;
	
}

void get_a4(int *a, int *b, int *c, int *d)
{
	*a = 1;
	*b = 2;
	*c = 3;
	*d = 4;	
}



int main_01()
{
	int a = 100;
	int b = 0;
	int a1, a2, a3, a4;
	int *p = NULL;

	//������ϵ��ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ
	p = &a;  //ͨ��*�����ڴ�

	*p = 22;
	/*ͨ��ָ���Ӹ�ֵ
	1.��������
	2.������ϵ
	3.ͨ��*�����ڴ�
	*/

    b = get_a();
	printf("b = %d\n", b);

	get_a2(b);
	printf("b2 = %d\n", b); //b��ֵΪ10������22.main�е�b��get_a2()��b�ǲ�ͬ�ġ�

	//�����ͨ���βθı�ʵ�ε��ڴ����ݣ�ֵ����������ַ����
    //ʵ�Σ��β�
	get_a3(&b); //�ں�������ʱ��������ϵ
	printf("b3 = %d\n", b);

	get_a4(&a1, &a2, &a3, &a4);
	printf("a1 = %d, a2 = %d, a3 = %d, a4 = %d", a1, a2, a3, a4);

	printf("\n");
	system("pause");
	return 0;
}

void fun2(int *p)
{
	p = (int *)0xaabb;
    printf("fun2: = %p\n", p);
}

void fun3(int **p)
{
	*p = (int *)0xddff;
	printf("fun3 = %p\n", *p);
}


int main(void)
{
	//һ��������Ӧ�ö���һ���������͵�ָ�뱣�����ĵ�ַ
	//������ԭ�����ͻ����϶��һ��*
	//int a = 10;
	//int *p = &a;
	//int **q = &p;
	//printf("p��ַ = %d, qָ�� = %d\n", p,9 *q);
	
	/*����
	int *********t = NULL;
	int **********t1 = &t;
	*/
	int *p = (int *)0x1122;
	printf("p1 = %p\n", p);

	fun2(p);  //ֵ����
	printf("p1 = %p\n\n", p);

	fun3(&p);//��ַ���ݣ�������׻���ֵ�Ĵ��ݣ�
	printf("p1 = %p\n", p);


	printf("\n");
	system("pause");
	return 0;
}


 