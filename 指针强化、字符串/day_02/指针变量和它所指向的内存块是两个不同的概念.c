#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	char *p = NULL;
	char buf[] = "abcdef";
	char *buf2 = "aaasssddd";
	char buf3[] = "sfdsfsfsdf";
	char *p2 = NULL;
	p = buf;
	printf("p2 = %s\n", p);
	//printf("p1��ַ = %d", p);

	//ָ�������ָ����ڴ����������ͬ�ĸ���
	p = p + 1; //�ı���ָ�������ֵ���ı���ָ���ָ��

	//printf("p2��ַ = %d", p);
	printf("%s\n", p);
	//д�ڴ�ʱ��һ��Ҫȷ���ڴ��д
	buf2[2] = '1';  //error  ��ʱ��aaasssddd���������ֳ������������޸ģ��ڴ治�ɸģ�
	//Ȼ��
	buf3[1] = '1'; //��ok��
	p2 = buf3;
	strcpy(p2,"rgrgrgrgr"); //error  ��������NULL�ͷǷ���ַ�����ڴ�
	printf("buf3 = %s\n", p2);
	printf("\n");
	system("pause");
	return 0;
}
				