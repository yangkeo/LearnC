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
	printf(" 1. �����ϵ����Ϣ\n");
	printf(" 2. ɾ��ָ����ϵ����Ϣ\n");
	printf(" 3. ����ָ����ϵ����Ϣ\n");
	printf(" 4. �޸�ָ����ϵ����Ϣ\n");
	printf(" 5. ��ʾ������ϵ����Ϣ\n");
	printf(" 6. ���������ϵ��\n");
	printf(" 7. ��������������\n");
	printf(" 8 .������ϵ�˵��ļ�\n");
	printf(" 9. ������ϵ��\n");
	printf(" 0. �˳�\n");
	printf("========================\n");
	printf("������Ҫѡ���������ţ�");
	//fflush(stdin);
	scanf("%d", &i);
	return i;
}

int Judge_Input_Legal(int choice)
{
	if (choice < 0 || choice > 9)
	{
		printf("�����������������룡\n");
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
	printf("������Ҫ�����ϵ�˵���Ϣ��\n");
	printf("����������");
	scanf("%s", person_info->name);
	printf("�����Ա�");
	scanf("%s", person_info->sex);
	printf("�������䣺");
	scanf("%s", person_info->age);
	printf("����绰��");
	scanf("%s", person_info->phone);
	printf("�����ַ��");
	scanf("%s", person_info->adress);
	g_address_book.size++;
	printf("�����ϵ�˳ɹ�\n");
}

void Delet_Contact()
{
	PersonInfo *person_info = &g_address_book.persons;
	int num = 0;
	printf("������Ҫɾ����ϵ�˵���ţ�");
	scanf("%d", &num);
	if (num < 0 || num >= g_address_book.size)
	{
		printf("��������");
		return;
	}
	*(person_info + num) = *(person_info + g_address_book.size - 1);
	g_address_book.size--;
	printf("ɾ����ϵ�˳ɹ�\n");
}

void Search_Contact()
{
	char search_name[1024] = " ";
	PersonInfo *person_info = &g_address_book.persons;
	printf("������Ҫ���ҵ�������");
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
	printf("������Ҫ�޸ĵ���ţ�");
	scanf("%d", &num);
	printf("�������µ�������");
	scanf("%s", (person_info + num)->name);
	printf("�������µ��Ա�");
	scanf("%s", (person_info + num)->sex);
	printf("�������µ����䣺");
	scanf("%s", (person_info + num)->age);
	printf("�������µĵ绰��");
	scanf("%s", (person_info + num)->phone);
	printf("�������µ�סַ��");
	scanf("%s", (person_info + num)->adress);
	printf("��ϵ����Ϣ�޸ĳɹ�\n");
}

void Print_Contact()
{
	PersonInfo *person_info = &g_address_book.persons;
	printf("��ӡ��%d����ϵ����Ϣ���£�\n", g_address_book.size);
	printf("���\t����\t�Ա�\t����\t�绰\tסַ\n");
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
	printf("��ӡȫ����Ϣ�ɹ�\n");
}

void Clear_Contact()
{
	g_address_book.size = 0;
	printf("ȫ����ճɹ�");
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
	printf("����ɹ�\n");
}

void Save_Contact_file()
{
	PersonInfo *person_info = &g_address_book.persons;
	FILE *pFile;
	pFile = fopen("Contacts.txt", "w");
	fprintf(pFile, "%d\n", g_address_book.size);
	fprintf(pFile, "���\t����\t�Ա�\t����\t�绰\tסַ\n");
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
	printf("������Ϣ�ɹ���\n");
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
	printf("��Ϣ��ȡ�ɹ���\n");

}
int main()
{
	Func arr[] =
	{
		Empty,//�����ã�ֻΪ������0��Ԫ��ռ�ã�ʹ����������±��Ӧ
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
		int choice = Menu();     //��ӡ�˵�����ȡ�û�����
		choice = Judge_Input_Legal(choice);
		if (choice == 0) break; //�ж��û������Ƿ�Ϸ�
		if (choice < 0) continue;
		arr[choice]();//ת�Ʊ���ú���
	}
	system("pause");
	return 0;
}





