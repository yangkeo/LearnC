#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(pcontact list)
{
	list->data = (info *)malloc(sizeof(info)* MEMBER_MAX);
	list->size = 0;
	list->capacity = MEMBER_MAX;
	//ÿ�γ�ʼ���Ǽ���һ���ļ�����ֹ����¼����ڱ������ļ�ʱ�����ϴ�
	//�򿪳���ʱ�������Ϣ
	LoadContact(list);
}

//�����ϵ��
void AddContact(pcontact list)
{
	info tmp_member;
	if (CheckCapacity(list) == 0)
	{
		printf("��Ա���������ʧ�ܣ�");
		return;
	}

	printf("����������:");
	scanf("%s", tmp_member.name);
	printf("�������Ա�:");
	scanf("%s", tmp_member.sex);
	printf("����������:");
	scanf("%d", &tmp_member.age);
	printf("������绰:");
	scanf("%s", tmp_member.tele);
	printf("�������ַ:");
	scanf("%s", tmp_member.addr);
	list->data[list->size] = tmp_member;
	printf("��ӳɹ���\n");
	list->size++;
}

//ɾ����ϵ��
void DellContact(pcontact list)
{
	char tmp_name[NAME_MAX] = { 0 };
	int ret = 0;
	printf("����������:");
	scanf("%s", tmp_name);
	ret = FindContactAddr(list, tmp_name);
	if (ret == -1)
	{
		printf("�޴���ϵ�ˣ�\n");
		return;
	}
	for (ret; ret < list->size - 1; ret++)
	{
		list->data[ret] = list->data[ret + 1];
	}
	printf("ɾ���ɹ���\n");
	list->size--;
}

//������ϵ��
void FindContact(pcontact list)
{
	char tmp_name[NAME_MAX] = { 0 };
	printf("����������:");
	scanf("%s", tmp_name);
	for (int i = 0; i < list->size; i++)
	{
		if (strcmp(tmp_name, list->data[i].name) == 0)
		{
			printf("===============================\n");
			printf("����:%s\n", list->data[i].name);
			printf("�Ա�:%s\n", list->data[i].sex);
			printf("����:%d\n", list->data[i].age);
			printf("�绰:%s\n", list->data[i].tele);
			printf("��ַ:%s\n", list->data[i].addr);
			printf("===============================\n");
			return;
		}
	}
	printf("�޴���ϵ�ˣ�\n");
}

//������ϵ��������data�ڼ���λ��
int FindContactAddr(pcontact list, char *tmp_name)
{
	for (int i = 0; i < list->size; i++)
	{
		if (strcmp(tmp_name, list->data[i].name) == 0)
			return i;
	}
	return -1;
}

//�޸���ϵ��
void ModContact(pcontact list)
{
	info tmp_member;
	int ret = 0;
	printf("����������:"); 
	scanf("%s", tmp_member.name);
	ret = FindContactAddr(list, tmp_member.name);
	if (ret == -1)
	{
		printf("�޴���ϵ�ˣ�\n");
		return;
	}
	printf("�������Ա�:");
	scanf("%s", tmp_member.sex);
	printf("����������:");
	scanf("%s", &tmp_member.age);
	printf("������绰:");
	scanf("%s", tmp_member.tele);
	printf("�������ַ:");
	scanf("%s", tmp_member.addr);
	list->data[ret] = tmp_member;
	printf("�޸ĳɹ�!\n");
}

//��ϵ������ѡ�񷨣�
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

//����ϴζ�̬���ٵĿռ��Ƿ��ã�����ʱ��������
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

//��ʾ������ϵ��
void ShowContact(pcontact list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("============��%dλ==============\n", i + 1);
		printf("����:%s\n", list->data[i].name);
		printf("�Ա�:%s\n", list->data[i].sex);
		printf("����:%d\n", list->data[i].age);
		printf("�绰:%s\n", list->data[i].tele);
		printf("��ַ:%s\n", list->data[i].addr);
		printf("===============================\n");
	}
}

//���ļ��м�����ϵ�˵��ڴ�
void LoadContact(pcontact list)
{
	info tmp_member;
	FILE *pf = NULL;
	pf = fopen("./contatc.dat", "rb");
	if (pf == NULL)
		perror("fopen error");
	//�����ڴ���ȡ��һ�ζ�1�飬1���С��sizeof(info)
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
		printf("���سɹ���\n");
	}
}

//����ϵ�˴��ڴ��б��浽�ļ�
void SaveContact(pcontact list)
{
	FILE *pf = NULL;
	pf = fopen("./contatc.dat", "wb");
	if (pf == NULL)
		perror("fopen error");
	for (int i = 0; i < list->size; i++)
	{
		//�����ڴ��д�룬һ��д1�飬1���С��sizeof(info)
		fwrite(list->data + i, sizeof(info), 1, pf);
	}	
	if (pf != NULL)
	{
		fclose(pf);
		pf = NULL;
		printf("����ɹ���\n");
	}
}