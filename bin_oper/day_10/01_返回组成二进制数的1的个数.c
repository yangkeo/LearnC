#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	int n = 0;
	int tmp = 0;
	while (scanf("%d", &n))
	{
		tmp = n;
		int count = 0;
		while (tmp != 0)
		{
			count += tmp % 2;
			tmp >>= 1;
		}
		printf("���%d����������1�ĸ���Ϊ%d\n", n, count);
	}

	printf("\n");
	system("pause");
	return 0;
}

