#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PERSON_SIZE 1024
typedef void(*Func)();
typedef struct PersonInfo
{
	char name[1024];
	char sex[1024];
	char age[1024];
	char phone[1024];
	char adress[1024];
} PersonInfo;

typedef struct AdressBook
{
	PersonInfo persons[MAX_PERSON_SIZE];
	int size;

} AdressBook;

AdressBook g_address_book;
void Init()
{
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_SIZE; i++)
	{
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
		g_address_book.persons[i].adress[0] = '\0';
		g_address_book.persons[i].sex[0] = '\0';
		g_address_book.persons[i].age[0] = '\0';
	}
}
int Menu()
{
	int i = -1;
	printf("========================\n");
	printf(" 1. 添加联系人信息\n");
	printf(" 2. 删除指定联系人信息\n");
	printf(" 3. 查找指定联系人信息\n");
	printf(" 4. 修改指定联系人信息\n");
	printf(" 5. 显示所有联系人信息\n");
	printf(" 6. 清空所有联系人\n");
	printf(" 7. 排序（以名字排序）\n");
	printf(" 8 .保存联系人到文件\n");
	printf(" 9. 加载联系人\n");
	printf(" 0. 退出\n");
	printf("========================\n");
	printf("请输入要选择操作的序号：");
	//fflush(stdin);
	scanf("%d", &i);
	return i;
}

int Judge_Input_Legal(int choice)
{
	if (choice < 0 || choice > 9)
	{
		printf("输入有误请重新输入！\n");
		return -1;
	}
	if (choice == 0)
	{
		printf("Goodbye\n");
		return 0;
	}
	return choice;
}

void Empty()
{
	//TMOD
}
void Add_Contact()
{
	PersonInfo *person_info = &g_address_book.persons[g_address_book.size];
	printf("请输入要添加联系人的信息：\n");
	printf("输入姓名：");
	scanf("%s", person_info->name);
	printf("输入性别：");
	scanf("%s", person_info->sex);
	printf("输入年龄：");
	scanf("%s", person_info->age);
	printf("输入电话：");
	scanf("%s", person_info->phone);
	printf("输入地址：");
	scanf("%s", person_info->adress);
	g_address_book.size++;
	printf("添加联系人成功\n");
}

void Delet_Contact()
{
	PersonInfo *person_info = &g_address_book.persons;
	int num = 0;
	printf("请输入要删除联系人的序号：");
	scanf("%d", &num);
	if (num < 0 || num >= g_address_book.size)
	{
		printf("输入有误");
		return;
	}
	*(person_info + num) = *(person_info + g_address_book.size - 1);
	g_address_book.size--;
	printf("删除联系人成功\n");
}

void Search_Contact()
{
	char search_name[1024] = " ";
	PersonInfo *person_info = &g_address_book.persons;
	printf("请输入要查找的姓名：");
	scanf("%s", search_name);
	for (int i = 0; i < g_address_book.size; i++)
	{
		if (0 == strcmp((g_address_book.persons + i)->name, search_name))
		{
			printf("[%d]\t%s\t%s\t%s\t%s\t%s\n",
				i,.
				(person_info + i)->name,
				(person_info + i)->sex,
				(person_info + i)->age,
				(person_info + i)->phone,
				(person_info + i)->adress
				);
		}
	}

}

void Update_Contact()
{
	int num = 0;
	PersonInfo *person_info = &g_address_book.persons;
	printf("请输入要修改的序号：");
	scanf("%d", &num);
	printf("请输入新的姓名：");
	scanf("%s", (person_info + num)->name);
	printf("请输入新的性别：");
	scanf("%s", (person_info + num)->sex);
	printf("请输入新的年龄：");
	scanf("%s", (person_info + num)->age);
	printf("请输入新的电话：");
	scanf("%s", (person_info + num)->phone);
	printf("请输入新的住址：");
	scanf("%s", (person_info + num)->adress);
	printf("联系人信息修改成功\n");
}

void Print_Contact()
{
	PersonInfo *person_info = &g_address_book.persons;
	printf("打印共%d条联系人信息如下：\n", g_address_book.size);
	printf("序号\t姓名\t性别\t年龄\t电话\t住址\n");
	for (int i = 0; i < g_address_book.size; i++)
	{
		printf("[%d]\t%s\t%s\t%s\t%s\t%s\n",
			i,
			(person_info + i)->name,
			(person_info + i)->sex,
			(person_info + i)->age,
			(person_info + i)->phone,
			(person_info + i)->adress
			);
	}
	printf("打印全部信息成功\n");
}

void Clear_Contact()
{
	g_address_book.size = 0;
	printf("全部清空成功");
}

void Sort_Contact()
{
	PersonInfo *person_info = &g_address_book.persons;
	//PersonInfo *PersonInfo_tmp = &g_address_book.persons[g_address_book.size+1];
	char PersonInfo_tmp[1024] = " ";
	for (int i = 0; i < g_address_book.size; i++)
	{
		for (int j = 0; j < g_address_book.size - i - 1; j++)
		{
			if (strcmp((person_info + j)->name, (person_info + j + 1)->name) > 0)
			{
				//*PersonInfo_tmp = *(person_info + j);
				//*(person_info + j) = *(person_info + j + 1);
				//*(person_info + j + 1) = *PersonInfo_tmp;
				strcpy(PersonInfo_tmp, person_info + j);
				strcpy(person_info + j, person_info + j + 1);
				strcpy(person_info + j + 1, PersonInfo_tmp);
			}
		}
	}
	printf("排序成功\n");
}

void Save_Contact_file()
{
	PersonInfo *person_info = &g_address_book.persons;
	FILE *pFile;
	pFile = fopen("Contacts.txt", "w");
	fprintf(pFile, "%d\n", g_address_book.size);
	fprintf(pFile, "序号\t姓名\t性别\t年龄\t电话\t住址\n");
	for (int i = 0; i < g_address_book.size; i++)
	{
		fprintf(pFile, "[%d]\t%s\t%s\t%s\t%s\t%s\n",
			i,
			(person_info + i)->name,
			(person_info + i)->sex,
			(person_info + i)->age,
			(person_info + i)->phone,
			(person_info + i)->adress
			);
	}
	fclose(pFile);
	printf("保存信息成功！\n");
}

void Load_Contact()
{
	PersonInfo *person_info = &g_address_book.persons;
	int num = 0;
	char str[] = " ";
	FILE *pFile;
	pFile = fopen("Contacts.txt", "r");
	fscanf(pFile, "%d\n", &g_address_book.size);
	fscanf(pFile, "%[^\n]%*c\n");
	for (int i = 0; i < g_address_book.size; i++)
	{
		fscanf(pFile, "[%d]\t%s\t%s\t%s\t%s\t%s\n",
			&num,
			&(person_info + i)->name,
			&(person_info + i)->sex,
			&(person_info + i)->age,
			&(person_info + i)->phone,
			&(person_info + i)->adress
			);
	}
	fclose(pFile);
	printf("信息读取成功！\n");

}
int main()
{
	Func arr[] =
	{
		Empty,//无作用，只为把数组0号元素占用，使序号与数组下标对应
		Add_Contact,
		Delet_Contact,
		Search_Contact,
		Update_Contact,
		Print_Contact,
		Clear_Contact,
		Sort_Contact,
		Save_Contact_file,
		Load_Contact
	};
	Init();
	while (1)
	{
		int choice = Menu();     //打印菜单并读取用户输入
		choice = Judge_Input_Legal(choice);
		if (choice == 0) break; //判断用户输入是否合法
		if (choice < 0) continue;
		arr[choice]();//转移表调用函数
	}
	system("pause");
	return 0;
}





