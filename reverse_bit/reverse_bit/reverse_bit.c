#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0;
	int tmp[32] = { 0 };
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		tmp[i] = value % 2;
		value >>= 1;
		if (value == 0)
			break;
	}
	for (i = 0; i < 31; i++)
	{
		ret = ret^tmp[i];
		ret <<= 1;
	}
	return ret;
}

unsigned int reverse_bit_1(unsigned int value)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < 32; i++)
	{
		ret += ((value >> i) & 1) * pow(2 , 31 - i);
	}
	return ret;
}

int main(void)
{
	unsigned int n = 0;
	scanf("%d", &n);
	printf("%u\n", n);
	n = reverse_bit_1(n);
	printf("%u\n", n);

	printf("\n");
	system("pause");
	return 0;
}