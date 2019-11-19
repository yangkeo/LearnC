#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "contact.h"

enum opt
{
	Exit,
	Add,
	Dell,
	Find,
	Mod,
	Show,
	Load,
	Save,
	Sort,
};

void menu(void)
{
	printf("/*========================ͨѶ¼======================*/\n");
	printf("/*=          0.�˳�ͨѶ¼    1.�����ϵ��            =*/\n");
	printf("/*=          2.ɾ����ϵ��    3.������ϵ��            =*/\n");
	printf("/*=          4.�޸���ϵ��    5.��ʾ������ϵ��        =*/\n");
	printf("/*=          6.������ϵ��    7.������ϵ��            =*/\n");
	printf("/*=          8.��ϵ������                            =*/\n");
	printf("/*====================================================*/\n");
}

void TestContact(void)
{
	contact pc;
	InitContact(&pc);
	int opt = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &opt);
		switch (opt)
		{
		case Exit:
			printf("�˳�ϵͳ...\n");
			break;
		case Add:
			AddContact(&pc);
			break;
		case Dell:
			DellContact(&pc);
			break;
		case Find:
			FindContact(&pc);
			break;
		case Mod:
			ModContact(&pc);
			break;
		case Show:
			ShowContact(&pc);
			break;
		case Load:
			LoadContact(&pc);
			break;
		case Save:
			SaveContact(&pc);
			break;
		case Sort:
			SortContact(&pc);
			break;
		default:
			printf("����ѡ��������������!\n");
			break;
		}

	} while (opt);
}

int main(void)
{
	TestContact();

	printf("\n");
	system("pause");
	return 0;
}