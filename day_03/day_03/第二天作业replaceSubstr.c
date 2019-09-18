#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceSubstr(char *src, char **dst, char *sub, char *new_sub)
{
	if (src == NULL || dst == NULL ||sub == NULL || new_sub == NULL)
	{
		return 1;
	}
	int a = 0;

	int len = strlen(src);
	int i = 0;
	char *start = src;
	char *p = NULL;
	char tmp[100] = { 0 };
	
	for (i = 0; i < len; i++)
	{
		p = strstr(start, sub);
		if (p != 0)
		{
			strncat(tmp, start, (p - start));
			strcat(tmp, new_sub);
			i = i + (p - start + strlen(sub));
			start = p + strlen(sub);			
		}
		else
		{
			strcat(tmp, start);
			i = i + (p +strlen(start));
			break;
		}
	}	
	printf("%s\n", tmp);
	char *q = NULL;
	q = (char *)malloc(100);
	strcpy(q, tmp);
	*dst = q;
	return 0;  	
}

void malloc_free_01(char *buf)
{
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}

void malloc_free_02(char **buf)
{
	if (*buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
}

void main(void)
{
	char *p = "mmmqqqqqqabcd11111abcd22222abcdqqqqqsss";   //"qqqqqqabcd11111abcd22222abcdqqqqq";
	char *buf = NULL;
	int ret = 0;

	ret = replaceSubstr(p, &buf, "abcd", "wyf");  //(p, &buf, "abcd", "edcba");
	if(ret != 0)
	{
		printf("replaceSubstr : err");
		system("pause");
		return;
	}
		
	printf("p = %s\n", p);
	printf("buf = %s\n",buf);
	
	malloc_free_02(&buf);



	printf("\n");
	system("pause");
	return 0;
}



