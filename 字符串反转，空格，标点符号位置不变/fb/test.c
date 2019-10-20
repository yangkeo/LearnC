#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

void my_str(char arr[100], int len)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == ' '|| i == len - 1)
		{
			y = i - 1;
			for (j = x; j < y; j++, y--)
			{
				swap(&arr[j], &arr[y]);
			}
		}
		if (arr[i] == ' ')
			x = i + 1;
	}
}

int main(void)
{
	char arr[100] = {0};
	while (gets(arr) != NULL)
	{
		int len = strlen(arr);
		my_str(arr, len);
		printf("%s", arr);
	}
	

	printf("\n");
	system("pause");
	return 0;
}