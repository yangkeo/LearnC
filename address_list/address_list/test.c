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
	printf("/*========================通讯录======================*/\n");
	printf("/*=          0.退出通讯录    1.添加联系人            =*/\n");
	printf("/*=          2.删除联系人    3.查找联系人            =*/\n");
	printf("/*=          4.修改联系人    5.显示所有联系人        =*/\n");
	printf("/*=          6.加载联系人    7.保存联系人            =*/\n");
	printf("/*=          8.联系人排序                            =*/\n");
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
		printf("请选择:>");
		scanf("%d", &opt);
		switch (opt)
		{
		case Exit:
			printf("退出系统...\n");
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
			printf("输入选项有误，重新输入!\n");
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