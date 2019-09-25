#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4. 键值对（“key = value”）字符串，在开发中经常使用
要求1：请自己定义一个接口，实现根据key获取.
要求2：编写测试用例。
要求3：键值对中间可能有n多空格，请去除空格

注意：键值对字符串格式可能如下：
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

	//从左往右移动，如果当前字符为空，而且没有结束
	while (p[begin] == ' ' && p[begin] != 0)
	{
		begin++; //位置从右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (p[end] == ' ' && end > 0)
	{
		end--; //往左移动
	}
	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //非空元素个数

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;

	/*//如何证明strncpy()拷贝不会自动加字符串结束符'\0'
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

	//查找匹配键值
	p = strstr(keyvaluebuf, keybuf);  //"key4        = value4"找key4找到返回首地址
	if (p == NULL)
	{
		return -2;
	}

	//如果找到，重新设置起点位置，跳过“key4”
	p = p + strlen(keybuf);  // "key4        =   value4"  ->  "       =   value"

	//查找 =
	p = strstr(p, "=");
	if (p == NULL)
	{
		return -3;
	}
	//如果找到，重新设置起点位置，跳过“=”
	p = p + strlen("=");  // " =   value" ->  "  value"

	//取非空字符
	ret = trimSpace(p, valuebuf);
	if (ret != 0)
	{
		printf("trimSpace err: %d\n", ret);		
		//system("pause");
		return ret;
	}
	//获取长度，通过*间接赋值
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