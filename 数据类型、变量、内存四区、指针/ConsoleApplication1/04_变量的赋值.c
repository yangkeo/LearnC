#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int main(void)
{
	//�������ʣ�һ�������ڴ�ռ����
	//
	int a;
	int *p;

	//ֱ�Ӹ�ֵ
	a= 10;
	printf("a:%d\n", a);
	//��Ӹ�ֵ
	printf("&a:%d\n", &a);
	p= &a;
	printf("p= %d\n", p);

	*p=20;
	printf("a:%d", a);
	printf("\n");
	system("pause");
	return 0;
	
}