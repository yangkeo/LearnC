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
	unsigned char dst[100] = { 0 };  //����
	int dstlen = 0;
	int ret = 0;

	//����
	ret = DesEnc(buf, srclen, dst, &dstlen);
	if (ret != 0)
	{
		printf("����ʧ��...:%d\n", ret);
		return -1;
	}
	printf("%s���ܺ�%s\n", buf, dst);


	//����
	unsigned char tmp[100] = { 0 };
	int tmplen;
	ret = DesDec(dst, dstlen, tmp, &tmplen);
	if (ret != 0)
	{
		printf("����ʧ��...:%d\n", ret);
		return -1;
	}
	if (tmplen != srclen)
	{
		printf("���ܺ�ĳ��Ⱥ�ԭ����һ��\n");
		return -2;
	}
	printf("%s���ܺ�%s\n", dst, tmp);

	printf("\n");
	system("pause");
	return 0;
}

void menu()
{
	printf("===================================\n");
	printf("1 �����ļ�\n");
	printf("2 �����ļ�\n");
	printf("3 ����\n");
	printf("4 �˳�\n");
	printf("===================================\n");
}

//�����ļ�����4K��С���ļ���srcBuf ����-> dstBuf, dst -> д�ļ�
//С��4K��С���ļ���srcBuf ����-> dstBuf, dst -> д�ļ�
void EncFile(void)
{
	FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //Դ�ļ�·�� ����Ҫ���ܵ��ļ�·��
	char wPath[512] = { 0 }; //Ŀ��·����������ܺ���ļ�
	unsigned char srcBuf[SIZE] = { 0 }; //4K
	int rLen = 0;
	unsigned char dstBuf[SIZE] = { 0 }; //4K
	int wLen = 0;
	int ret = 0;

	printf("��������Ҫ���ܵ��ļ���");
	scanf("%s", rPath);

	printf("��������ܺ���ļ���");
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
	//ѭ����ȡ�ļ�
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
			printf("DesEnc_raw ���ܵ���4K error\n");
			goto End;
			return;
		}
		//д���ܺ���ļ�
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("fwrite д���ܵ���4K error\n");
			goto End;
			return;
		}

	}

	ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesEnc_raw ����С��4K error\n");
		goto End;
		return;
	}
	//д���ܺ���ļ�
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("fwrite д����С��4K error\n");
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

//�����ļ�
void DecFile()
{
	FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //Դ�ļ�·�� ����Ҫ���ܵ��ļ�·��
	char wPath[512] = { 0 }; //Ŀ��·����������ܺ���ļ�
	unsigned char srcBuf[SIZE] = { 0 }; //4K
	int rLen = 0;
	unsigned char dstBuf[SIZE] = { 0 }; //4K
	int wLen = 0;
	int ret = 0;

	printf("��������Ҫ���ܵ��ļ���");
	scanf("%s", rPath);

	printf("��������ܺ���ļ���");
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
	//ѭ����ȡ�ļ�
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
			printf("DesEnc_raw ���ܵ���4K error\n");
			goto End;
			return;
		}
		//д���ܺ���ļ�
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("fwrite д���ܵ���4K error\n");
			goto End;
			return;
		}

	}

	ret = DesDec(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesEnc_raw ����С��4K error\n");
		goto End;
		return;
	}
	//д���ܺ���ļ�
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("fwrite д����С��4K error\n");
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
			system("cls"); //����
			break;
		default:
			exit(0);  //�˳�����
			break;
		}
	}
	 
	printf("\n");
	system("pause");
	return 0;
}