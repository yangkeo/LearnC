#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Teacher
{
	char name[64];  //64
	int age;  //4
	int id; //4
}Teacher;


int main(void)
{
	struct
	{
		double c;
		int a;		
		short b;
	}A;
	int n = sizeof(A);
	printf("%d\n", n);


	printf("\n");
	system("pause");
	return 0;
}