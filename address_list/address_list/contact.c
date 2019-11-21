#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

//初始化通讯录
void InitContact(pcontact list)
{
	list->data = (info *)malloc(sizeof(info)* MEMBER_MAX);
	list->size = 0;
	list->capacity = MEMBER_MAX;
	//每次初始化是加载一遍文件，防止最新录入的在保存在文件时覆盖上次
	//打开程序时保存的信息
	LoadContact(list);
}

//添加联系人
void AddContact(pcontact list)
{
	info tmp_member;
	if (CheckCapacity(list) == 0)
	{
		printf("成员已满，添加失败！");
		return;
	}

	printf("请输入姓名:");
	scanf("%s", tmp_member.name);
	printf("请输入性别:");
	scanf("%s", tmp_member.sex);
	printf("请输入年龄:");
	scanf("%d", &tmp_member.age);
	printf("请输入电话:");
	scanf("%s", tmp_member.tele);
	printf("请输入地址:");
	scanf("%s", tmp_member.addr);
	list->data[list->size] = tmp_member;
	printf("添加成功！\n");
	list->size++;
}

//删除联系人
void DellContact(pcontact list)
{
	char tmp_name[NAME_MAX] = { 0 };
	int ret = 0;
	printf("请输入姓名:");
	scanf("%s", tmp_name);
	ret = FindContactAddr(list, tmp_name);
	if (ret == -1)
	{
		printf("无此联系人！\n");
		return;
	}
	for (ret; ret < list->size - 1; ret++)
	{
		list->data[ret] = list->data[ret + 1];
	}
	printf("删除成功！\n");
	list->size--;
}

//查找联系人
void FindContact(pcontact list)
{
	char tmp_name[NAME_MAX] = { 0 };
	printf("请输入姓名:");
	scanf("%s", tmp_name);
	for (int i = 0; i < list->size; i++)
	{
		if (strcmp(tmp_name, list->data[i].name) == 0)
		{
			printf("===============================\n");
			printf("姓名:%s\n", list->data[i].name);
			printf("性别:%s\n", list->data[i].sex);
			printf("年龄:%d\n", list->data[i].age);
			printf("电话:%s\n", list->data[i].tele);
			printf("地址:%s\n", list->data[i].addr);
			printf("===============================\n");
			return;
		}
	}
	printf("无此联系人！\n");
}

//查找联系人在数组data第几个位置
int FindContactAddr(pcontact list, char *tmp_name)
{
	for (int i = 0; i < list->size; i++)
	{
		if (strcmp(tmp_name, list->data[i].name) == 0)
			return i;
	}
	return -1;
}

//修改联系人
void ModContact(pcontact list)
{
	info tmp_member;
	int ret = 0;
	printf("请输入姓名:"); 
	scanf("%s", tmp_member.name);
	ret = FindContactAddr(list, tmp_member.name);
	if (ret == -1)
	{
		printf("无此联系人！\n");
		return;
	}
	printf("请输入性别:");
	scanf("%s", tmp_member.sex);
	printf("请输入年龄:");
	scanf("%s", &tmp_member.age);
	printf("请输入电话:");
	scanf("%s", tmp_member.tele);
	printf("请输入地址:");
	scanf("%s", tmp_member.addr);
	list->data[ret] = tmp_member;
	printf("修改成功!\n");
}

//联系人排序（选择法）
void SortContact(pcontact list)
{
	info tmp_member;
	for (int i = 0; i < list->size - 2; i++)
	{
		for (int j = 1; j < list->size - 1; j++)
		{
			if (strcmp(list->data[i].name, list->data[j].name) > 0)
			{
				tmp_member = list->data[i];
				list->data[i] = list->data[j];
				list->data[j] = tmp_member;
			}
		}
	}
}

//检查上次动态开辟的空间是否够用，不够时继续开辟
int CheckCapacity(pcontact list)
{
	if (list->size == list->capacity)
	{
		info *tmp = (info *)malloc(sizeof(info)* (list->capacity + 10));
		if (tmp == NULL)
			return 0;
		memcpy(tmp, list->data, sizeof(info) * list->size);
		free(list->data);
		list->data = tmp;
		list->capacity += 10;
	}
	return 1;
}

//显示所有联系人
void ShowContact(pcontact list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("============第%d位==============\n", i + 1);
		printf("姓名:%s\n", list->data[i].name);
		printf("性别:%s\n", list->data[i].sex);
		printf("年龄:%d\n", list->data[i].age);
		printf("电话:%s\n", list->data[i].tele);
		printf("地址:%s\n", list->data[i].addr);
		printf("===============================\n");
	}
}

//从文件中加载联系人到内存
void LoadContact(pcontact list)
{
	info tmp_member;
	FILE *pf = NULL;
	pf = fopen("./contatc.dat", "rb");
	if (pf == NULL)
		perror("fopen error");
	//按照内存块读取，一次读1块，1块大小是sizeof(info)
	while (fread(&tmp_member, sizeof(info), 1, pf))
	{
		if (CheckCapacity(list))
		{
			list->data[list->size] = tmp_member;
			list->size++;
		}
	}
	if (pf != NULL)
	{
		fclose(pf);
		pf = NULL;
		printf("加载成功！\n");
	}
}

//将联系人从内从中保存到文件
void SaveContact(pcontact list)
{
	FILE *pf = NULL;
	pf = fopen("./contatc.dat", "wb");
	if (pf == NULL)
		perror("fopen error");
	for (int i = 0; i < list->size; i++)
	{
		//按照内存块写入，一次写1块，1块大小是sizeof(info)
		fwrite(list->data + i, sizeof(info), 1, pf);
	}	
	if (pf != NULL)
	{
		fclose(pf);
		pf = NULL;
		printf("保存成功！\n");
	}
}