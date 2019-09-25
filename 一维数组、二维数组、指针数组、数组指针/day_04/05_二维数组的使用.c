#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main01(void)
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	//+16
	//��ά���������������0�е��׵�ַ �������ڵ�0����Ԫ�ص�ַ����Ȼֵһ����
	//���ǲ�����һ��
	printf("a:%d, a+1:%d\n", a2, a2 + 1); 
	printf("%d  %d\n", *(a2 + 0), *(a2 + 0) + 1); //��0����Ԫ�ص�ַ  �͵�0�еڶ���Ԫ�ص�ַ
	printf("%d  %d\n",a2[0], a2[0] + 1);  //����һ�еȼۣ���������һ�е� * ���൱����һ�е� []

	//int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//a ���������0���׵�ַ
	//a + i -> &a[i]:�����i���׵�ַ
	//*(a+i) -> a[i]�����i����Ԫ�صĵ�ַ
	//*(a+i)+j -> &a[i][j] = �����i�е�j��Ԫ�صĵ�ַ
	//*((a+i)+j) -> a[i][j] = ��i�е�j��Ԫ�ص�ֵ





	printf("\n");
	system("pause");
	return 0;
}


void printA(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}


int main02(void)
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	
	printA((int *)a, sizeof(a) / sizeof(a[0][0]));


	printf("\n");
	system("pause");
	return 0;
}


int main03(void)
{
	int a[3][10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//3��a[4]��һλ����

#if 0
	//����һ������ָ�����
	int (*p)[10];
	p = a; //��0���׵�ַ��p�ȼ��ڶ�ά������
	printf("p:%d, p+1:%d\n", p, p + 1); //10 * 4 = 40

#endif

	//��������ָ�����ͣ��ٶ������
	typedef int(*P)[10];
	P p;
	p = a;



	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			//printf("%d ", p[i][j]);
			printf("%d ", *(*(p + i) + j)); //����һ�еȼ�
		}
		printf("\n");
	}

	//��һλ���鳤�ȵ�ʱ��sizeof()������Ԫ�ص�ַ
	char t[10];
	printf("sizeof(t):%d, sizeof(&t):%d\n", sizeof(t), sizeof(&t));

	//int a[3][10]
	printf("sizeof(a[0]):%d, sizeof(&a[0]):%d\n", sizeof(a[0]), sizeof(&a[0]));


	printf("\n");
	system("pause");
	return 0;
}


void printArray(int a[3][4]) //5k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

//�����βζ����˻�Ϊָ�룬ָ�벽����һ��һ��
void printArray01(int a[][4]) //7k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


//������ָ��
void printArray02(int (*p)[4]) //9k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", p[i][j]);   //����һ�еȼ�
		}
		printf("\n");
	}
}


//������ָ��

typedef int(*Q)[4];
void printArray03(Q p) //9k
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", p[i][j]);   //����һ�еȼ�
		}
		printf("\n");
	}
}

int main(void)
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printArray03(a);


	printf("\n");
	system("pause");
	return 0;
}