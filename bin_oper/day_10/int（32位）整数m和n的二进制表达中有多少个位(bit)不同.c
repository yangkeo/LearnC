#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int m = 0;
	int n = 0;
	int tmp = 0;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int count = 0;
		tmp = m ^ n;
		while (tmp)
		{
			count += tmp % 2;
			tmp >>= 1;
		}
		printf("%d与%d共有%d位不同\n", m, n, count);
	}

	printf("\n");
	system("pause");
	return 0;
}

