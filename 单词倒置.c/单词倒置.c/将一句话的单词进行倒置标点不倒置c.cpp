#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *start,char *end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
	}
}

int main(void)
{
	char input[100];
	gets(input);
	reverse(input, input + strlen(input) - 1);
	char* start = input;
	while (*start)
	{
		char *end = start;
		while (*end != ' ' && *end)
			end++;

		reverse(start, end - 1);

		if (*end)
			start = end + 1;
		else
			start = end;
	}
	printf("%s", input);

	printf("\n");
	system("pause");
	return 0;
}