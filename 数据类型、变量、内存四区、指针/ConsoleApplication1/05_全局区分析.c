#include"stdio.h"
#include"stdlib.h"
#include"string.h"

char *get_str1()
{
	char *p = "abcdef";  //���������ֳ�������ȫ����-ָ����abcdef�������ֳ��������������Ż��ͷ�

	return p;
}

char *get_str2()
{
	char *q = "abcdef";  //���������ֳ�������ȫ����-ָ����abcdef��

	return q;
}


int main(void)
{
	//����������ջ��������ֲ�������
	char *p = NULL;
	char *q = NULL;

	//%s:  ָ��ָ���ڴ����������, ��s�������һ���ַ���
	//%d�� ��ӡp�����ֵ
	p = get_str1();
	printf("p = %s, p = %d\n",p, p);  //01
	q = get_str2();
	printf("q = %s, q = %d",q, q);  //02  01��02�����ַ��ͬ������Ϊp��q����ֵ������
                                    // ��ͬ����˱�����Ϊ��ʡ�ռ��ʹp��qͬʱָ������ݵĵ�ַ
	printf("\n");
	system("pause");
	return 0;
	
}