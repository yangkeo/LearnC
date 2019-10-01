#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int main01(int a[],int n)
{	
	int i= 0;
	int j= 0;
	int tmp= 0;

	//选择法排序
	//如何看懂带算法的程序
	/*
	1.流程
	2.每个语句的功能
	3.试数
	4.调试
	5.模仿改
	6.不看代码写
	*/
	for(i= 0;i< n-1;i++)
	{
		for(j= i + 1;j< n; j++)
		{
			if(a[i]> a[j])  //升序
			{
				tmp= a[i];
				a[i]= a[j];
				a[j]= tmp;
			}
		}
	}
	printf("排序后：\n");
	for(i= 0;i< n;i++)
	{
		printf("%d",a[i]);
		printf(" ");
	}
	printf("\n");
	system("pause");
	return 0;
}

//如果数组作为函数参数，数组形参退化为指针。
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
	n= sizeof(a) / sizeof(a[0]);  //元素个数
	printf("排序前:\n");
	print_array(a, n);

	main01(a,n);

	printf("排序后：\n");
	print_array(a, n);

	printf("\n");
	system("pause");
	return 0;
}






