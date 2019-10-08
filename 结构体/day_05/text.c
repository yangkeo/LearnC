#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

#define SIZE 1024*4

int main01(void)
{
	unsigned char buf[] = "flsdfsdf13s51dfs5sdf35sdf3f21";
	int srclen = strlen(buf);
	unsigned char dst[100] = { 0 };  //密文
	int dstlen = 0;
	int ret = 0;

	//加密
	ret = DesEnc(buf, srclen, dst, &dstlen);
	if (ret != 0)
	{
		printf("加密失败...:%d\n", ret);
		return -1;
	}
	printf("%s加密后：%s\n", buf, dst);


	//解密
	unsigned char tmp[100] = { 0 };
	int tmplen;
	ret = DesDec(dst, dstlen, tmp, &tmplen);
	if (ret != 0)
	{
		printf("解密失败...:%d\n", ret);
		return -1;
	}
	if (tmplen != srclen)
	{
		printf("解密后的长度和原来不一致\n");
		return -2;
	}
	printf("%s解密后：%s\n", dst, tmp);

	printf("\n");
	system("pause");
	return 0;
}

void menu()
{
	printf("===================================\n");
	printf("1 加密文件\n");
	printf("2 解密文件\n");
	printf("3 清屏\n");
	printf("4 退出\n");
	printf("===================================\n");
}

//加密文件，以4K大小读文件，srcBuf 加密-> dstBuf, dst -> 写文件
//小于4K大小读文件，srcBuf 加密-> dstBuf, dst -> 写文件
void EncFile(void)
{
	FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //源文件路径 ，需要加密的文件路径
	char wPath[512] = { 0 }; //目标路径，保存加密后的文件
	unsigned char srcBuf[SIZE] = { 0 }; //4K
	int rLen = 0;
	unsigned char dstBuf[SIZE] = { 0 }; //4K
	int wLen = 0;
	int ret = 0;

	printf("请输入需要加密的文件：");
	scanf("%s", rPath);

	printf("请输入加密后的文件：");
	scanf("%s", wPath);

	rFd = fopen(rPath, "rb+");
	if (rPath == NULL)
	{
		perror("EncFile fopen rPath:\n");
		return;
	}

	wFd = fopen(wPath, "wb+");
	if (rPath == NULL)
	{
		perror("EncFile fopen wPath:\n");
		goto End;
		return;
	}
	//循环读取文件
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		if (rLen < SIZE)
		{
			break;
		}
		ret = DesEnc_raw(srcBuf, rLen, dstBuf, &wLen);
		if (ret != 0)
		{
			printf("DesEnc_raw 加密等于4K error\n");
			goto End;
			return;
		}
		//写加密后的文件
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("fwrite 写加密等于4K error\n");
			goto End;
			return;
		}

	}

	ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesEnc_raw 加密小于4K error\n");
		goto End;
		return;
	}
	//写加密后的文件
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("fwrite 写加密小于4K error\n");
		goto End;
		return;
	}
End:
	if (rFd != NULL)
	{
		fclose(rFd);
	}
	if (wFd != NULL)
	{
		fclose(wFd);
	}
}

//解密文件
void DecFile()
{
	FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //源文件路径 ，需要解密的文件路径
	char wPath[512] = { 0 }; //目标路径，保存解密后的文件
	unsigned char srcBuf[SIZE] = { 0 }; //4K
	int rLen = 0;
	unsigned char dstBuf[SIZE] = { 0 }; //4K
	int wLen = 0;
	int ret = 0;

	printf("请输入需要解密的文件：");
	scanf("%s", rPath);

	printf("请输入解密后的文件：");
	scanf("%s", wPath);

	rFd = fopen(rPath, "rb+");
	if (rPath == NULL)
	{
		perror("EncFile fopen rPath:\n");
		return;
	}

	wFd = fopen(wPath, "wb+");
	if (rPath == NULL)
	{
		perror("EncFile fopen wPath:\n");
		goto End;
		return;
	}
	//循环读取文件
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		if (rLen < SIZE)
		{
			break;
		}
		ret = DesDec_raw(srcBuf, rLen, dstBuf, &wLen); 
		if (ret != 0)
		{
			printf("DesEnc_raw 解密等于4K error\n");
			goto End;
			return;
		}
		//写解密后的文件
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("fwrite 写解密等于4K error\n");
			goto End;
			return;
		}

	}

	ret = DesDec(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesEnc_raw 加密小于4K error\n");
		goto End;
		return;
	}
	//写解密后的文件
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("fwrite 写加密小于4K error\n");
		goto End;
		return;
	}
End:
	if (rFd != NULL)
	{
		fclose(rFd);
	}
	if (wFd != NULL)
	{
		fclose(wFd);
	}
}

int main(void)
{
	int cmd;
	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			EncFile();
			break;
		case 2:
			DecFile();
			break;
		case 3:
			system("cls"); //清屏
			break;
		default:
			exit(0);  //退出进程
			break;
		}
	}
	 
	printf("\n");
	system("pause");
	return 0;
}