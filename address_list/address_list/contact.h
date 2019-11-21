#ifndef CONTACT_H
#define CONTACT_H

#define NAME_MAX 20
#define SEX_MAX 10
#define TEL_MAX 12
#define ADDR_MAX 20
#define MEMBER_MAX 1

typedef struct info
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TEL_MAX];
	char addr[ADDR_MAX];
}info;

typedef struct contact
{
	info *data;
	int size;
	int capacity;
}contact, *pcontact;

void InitContact(pcontact list);
void AddContact(pcontact list);
void DellContact(pcontact list);
void FindContact(pcontact list);
void ModContact(pcontact list);
void ShowContact(pcontact list);
void SortContact(pcontact list);
int CheckSize(pcontact list);
int FindContactAddr(pcontact list);
void LoadContact(pcontact list);
void SaveContact(pcontact list);

#endif
