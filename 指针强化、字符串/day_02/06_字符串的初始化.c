#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main_01(void);

/*
c����û���ַ������ͣ�ͨ���ַ�����ģ��
c�����ַ������ԡ�\0��������0

*/
int main_01(void)                 
{
	//��ָ������,û��0����������ӡ�����������
	char buf[] = {'a', 'b', 'c'};
	char buf1[100] = {'a', 'b', 'c'};
	char buf5[50] = {'1', 'a', 'b', '0', '7'};
	char buf6[50] = {'1', 'a', 'b', 0, '7'};//���ֻ��0ab
	char buf7[50] = {'1', 'a', 'b', '\0', '7'};//���Ҳֻ��0ab
	//ʹ���ַ�����ʼ������ã���
	char buf8[] = "dfjosijfosijfojf";
	char buf9[100] = "dfjosijfosijfojf";
	printf("buf = %s\n",buf);

	//ָ�����ȣ�����û�и��Ƶ�Ԫ�أ��Զ���0
	printf("buf = %s\n",buf1);

	/*
	char buf2[100] = { 0 };  //����Ԫ�ظ�ֵΪ0
	char buf3[2] = {'1', '2', '3'};//����Խ��
	*/
	
	printf("buf5 = %s\n", buf5);
	printf("buf6 = %s\n", buf6);
	printf("buf7 = %s\n", buf7);
	//strlen:���ַ������ȣ�����������0���ַ�'\0'
	//sizeof:�����鳤�ȣ���������0���ַ�'\0'
	printf("strlen = %d, sizeof = %d\n", strlen(buf8), sizeof(buf8));
	printf("strlen = %d, sizeof = %d\n", strlen(buf9), sizeof(buf9));
	printf("\n"); 
	system("pause");
	return 0;
}

int main()
{
	int i;	
	char buf[] = "dfsadggdfveargvdfv";
	int n = strlen(buf);
	char *p = NULL;


	//[]��ʽ
	for(i = 0; i < n; i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	//ָ�뷽��
	//����������������Ԫ�ص�ַ

	p = buf;
	for(i = 0; i < n; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	for(i = 0; i < n; i++)
	{
		printf("%c",*( p+i));
	}
	printf("\n");

	for(i = 0; i < n; i++)
	{
		printf("%c",*(buf+i));
	}
	printf("\n");

	//buf��p��ȫ�ȼ���
	//p++;
	//buf++;
	//bufֻ��һ�������������޸ģ����Բ���buf++(buf++�����޸�buf�����ֵ),��buf+i�������


 
	printf("\n");
	system("pause");
	return 0;
}







 