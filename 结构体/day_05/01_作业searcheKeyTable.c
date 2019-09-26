#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM(a) (sizeof(a)/sizeof(*a))

/*
���ܣ��ҵ�������ָ���ַ�����λ��
������
table:�ַ������飨ָ�����飩�׵�ַ
size������Ԫ�ظ���
key��ƥ���ַ�������"do"
pos��ƥ���ַ����������е�λ�ã���"do"��keywords[]��λ��Ϊ4
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int searcheKeyTable(const char *table[], const int size, const char* key, int *pos)
{
	if (table == NULL || key == NULL || pos == NULL)
	{
		return -1;
	}
	int i = 0;
	for (*pos = 0; *pos < size; (*pos)++)
	{
		i = strstr(table[*pos], key);
		if (i != NULL)
		{
			(*pos)++;
			break;
		}
	}

	return 0;
}

int main(void)
{
	const char* keywords[] = {
		"while",
		"case",
		"static",
		"do"
	};
	int n = 0, ret = 0;
	ret = searcheKeyTable(keywords, NUM(keywords), "do", &n);
	
	printf("%s��keywords[]��λ��Ϊ%d\n", "do", n);
	printf("%d \n", NUM(keywords));


	printf("\n");
	system("pause");
	return 0;
}