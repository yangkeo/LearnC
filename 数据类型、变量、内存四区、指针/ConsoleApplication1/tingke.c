#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int main01(int a[],int n)
{	
	int i= 0;
	int j= 0;
	int tmp= 0;

	//ѡ������
	//��ο������㷨�ĳ���
	/*
	1.����
	2.ÿ�����Ĺ���
	3.����
	4.����
	5.ģ�¸�
	6.��������д
	*/
	for(i= 0;i< n-1;i++)
	{
		for(j= i + 1;j< n; j++)
		{
			if(a[i]> a[j])  //����
			{
				tmp= a[i];
				a[i]= a[j];
				a[j]= tmp;
			}
		}
	}
	printf("�����\n");
	for(i= 0;i< n;i++)
	{
		printf("%d",a[i]);
		printf(" ");
	}
	printf("\n");
	system("pause");
	return 0;
}

//���������Ϊ���������������β��˻�Ϊָ�롣
void print_array(int a[10] , int n)
{
	int i= 0;
	for(i= 0;i< n;i++)
	{
		printf("%d",a[i]);
		printf(" ");
	}
	printf("\n");
}
int main(void)
{
	int a[]= {6,7,3,4,56,7,2};
	int n= 0;
	int i= 0;
	int j= 0;
	int tmp= 0;
	n= sizeof(a) / sizeof(a[0]);  //Ԫ�ظ���
	printf("����ǰ:\n");
	print_array(a, n);

	main01(a,n);

	printf("�����\n");
	print_array(a, n);

	printf("\n");
	system("pause");
	return 0;
}






