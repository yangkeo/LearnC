#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4. ��ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ.
Ҫ��2����д����������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�

ע�⣺��ֵ���ַ�����ʽ�������£�
"key1 = value1"
"key2 =       value2"
"key3  = value3"
"key4        = value4"
"key5   =   "
"key6   ="

int getKeyByValue(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int * valuebuflen);

int main(void)
{
//...
getKeyByValude("key1 =   valude1", "key1", buf, &len);
//...

return 0;
}
*/

int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}
	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0)
	{
		return;
	}

	//���������ƶ��������ǰ�ַ�Ϊ�գ�����û�н���
	while (p[begin] == ' ' && p[begin] != 0)
	{
		begin++; //λ�ô����ƶ�һλ
	}

	//���������ƶ��������ǰ�ַ�Ϊ��
	while (p[end] == ' ' && end > 0)
	{
		end--; //�����ƶ�
	}
	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //�ǿ�Ԫ�ظ���

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;

	/*//���֤��strncpy()���������Զ����ַ���������'\0'
	char dst[] = "aaaaaaaaaaaaaaa";
	strncpy(dst, "123", 3);
	printf("dst = %s\n", dst); //dst = "123aaaaaaaaaaaa"
	*/
}

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen)
{
	/*
	keyvaluebuf = "key4        = value4"
	keybuf = "key4"
	*/
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		return -1;
	}
	char *p = keyvaluebuf;
	int ret = 0;

	//����ƥ���ֵ
	p = strstr(keyvaluebuf, keybuf);  //"key4        = value4"��key4�ҵ������׵�ַ
	if (p == NULL)
	{
		return -2;
	}

	//����ҵ��������������λ�ã�������key4��
	p = p + strlen(keybuf);  // "key4        =   value4"  ->  "       =   value"

	//���� =
	p = strstr(p, "=");
	if (p == NULL)
	{
		return -3;
	}
	//����ҵ��������������λ�ã�������=��
	p = p + strlen("=");  // " =   value" ->  "  value"

	//ȡ�ǿ��ַ�
	ret = trimSpace(p, valuebuf);
	if (ret != 0)
	{
		printf("trimSpace err: %d\n", ret);		
		//system("pause");
		return ret;
	}
	//��ȡ���ȣ�ͨ��*��Ӹ�ֵ
	*valuebuflen = strlen(valuebuf);
	

	return 0;
}

int main(void)
{


	char *keyVal = "key4        =   value4    ";
	char *key = "key4";
	char value[100] = { 0 };
	int len = 0;
	int ret = 0;

	ret = getKeyByValue(keyVal, key, value, &len);
	if(ret != 0)
	{
		printf("getKeyByValue err: %d", ret);
		system("pause");
		return ret;
	}
	printf("val: %s\n", value);
	printf("len: %d\n", len);


#if 0
	char *p = "      abcddsgadsgefg      ";
	char buf[100] = { 0 };

	int ret = 0;
	ret = trimSpace(p, buf);
	if (ret != 0)
	{
		printf("trimSpace err: %d\n", ret);
		return ret;
	}

	printf("buf = %s\n", buf);
#endif
	printf("\n");
	system("pause");
	return 0;
}