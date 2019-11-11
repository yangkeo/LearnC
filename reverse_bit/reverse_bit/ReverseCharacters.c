#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReverStr(char *start, char *end)
{
	char tmp = 0;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

//void ReverseCharacters(char *str, int len)
//{
//	int left = 0;
//	int right = 0;
//	int i = 0;
//	int tmp = 0;
//	ReverStr(str, len);
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] == ' ')
//		{
//			right = i;
//			tmp = right - left + 1;
//			ReverStr(&str[left], tmp);
//			left = i;
//		}
//	}
//}

void ReverseCharacters(char *str)
{
	char *cur = str; 
	ReverStr(cur, cur + strlen(cur) - 1);
	while (*cur)
	{
		char *start = cur;
		while (*cur != ' ' && *cur != '\0')
			cur++;
		ReverStr(start, cur - 1);
		cur++;
	}	
}

int main(void)
{
	char str[30] = { 0 };
	char *end = NULL;
	gets(str);
	end = str + strlen(str);
	ReverseCharacters(str, end);
	printf("%s\n", str);

	printf("\n");
	system("pause");
	return 0;
}


