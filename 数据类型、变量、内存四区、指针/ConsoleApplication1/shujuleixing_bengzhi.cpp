#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int main(void)
{
	int a;  //���߱�����������4���ֽ�
	int b[10];  //����4*10���ֽ�
	/*
	���͵ı��ʣ��̶��ڴ���С����
	��ͨ��sizeof��������
	*/
	
	printf("sizeof(a)= %d, sizeof(b)= %d\n", sizeof(a), sizeof(b));

	//��ӡ��ַ
	//����������������Ԫ�صĵ�ַ
	printf("b:%d��&b:%d\n", b, &b);
	//b,&b���������Ͳ�һ��
	//b,������Ԫ�ص�ַ 
	//&b,����������׵�ַ��һ������4*10=40�ֽڣ�+1�� +40
	printf("b+1:%d��&b+1:%d\n", b+1, &b+1);

	//ָ�����ͳ��ȣ�32λ���򣬳���4
	//              64λ���򣬳���8
	char *******************p= NULL;
	int *q= NULL;
	printf("%d,%d\n",sizeof(p), sizeof(q));

	printf("\n");
	system("pause");
	return 0;
	
}