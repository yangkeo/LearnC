#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

char *get_str()
{
	int i = 0;
	char str[] = "abcdefgh";  //ջ��
	  printf("str[] = %s\n", str);
	return str;  //���ص��׵�ַ(���������е�*)
}

char *get_str2()
{
	char *tmp = (char *)malloc(100);
	if(tmp == NULL)
	{
		return NULL;
	}
	strcpy(tmp, "abcdefghi");
	return tmp;
}


int main(void)
{
	int i = 0;
	char buf[128] = { 0 };
	//strcpy(buf, get_str());  	
   	//printf("buf = %s\n",buf);  //�������п�����a~h���п������롣��Ϊget_str()���ظ�buf����str���׵�ַ����get_str()ִ����Ϻ�ջ���Ὣ�ռ��ͷ�str[]�е����ݿ��ܸı�
	char *p;
	p = get_str2();
	if(p != NULL)
	{
		printf("p = %s\n", p);
		free(p);
		p = NULL;
	}

	
	
	printf("\n");
	system("pause");
	return 0;
	
}