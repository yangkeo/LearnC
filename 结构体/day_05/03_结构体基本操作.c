#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
���ܣ�1��������p1���ַ���ȡ����
2���Ѷ�ά����buf2���ַ�ȡ����
3��������ַ�������p3, p3���ڶ�������Ķ�ά�ڴ�
4����p3���ַ�����������ͨ�� strcmp()��������
������
p1��ָ�������׵�ַ��char *p1[] = { "aa", "ccccccc", "bbbbbb" };
len1��p1Ԫ�ظ���
buf2����ά������Ԫ�ص�ַ��buf2[10][30] = { "111111", "3333333", "222222" };
len2: buf2�ַ�������
p3������ָ��ĵ�ַ����Ҫ�ٺ����ڷ����ά�ڴ棬����p1��buf2���ַ���������Ҫ����
len3������p3���ַ�������
*/

/*
1���ṹ�����Ͷ���
2���ṹ���������
3���ṹ�������ʼ��
4��typedef��������
5�����������ָ�뷨�����ṹ��
6���ṹ��Ҳ��һ���������ͣ��������ͣ��Զ�������
*/

//struct �ؼ���
//struct Tescher����һ���������
//{}�����зֺ�
struct Teacher
{
	char name[50];
	int age;
};

//2���ṹ���������
//1���ȶ��������ٶ�����������ã�
struct Teacher t1; //ȫ�ֱ���

//2���������͵�ͬʱ�������
struct Teacher2
{
	char name[50];
	int age;
}t3, t4;

struct 
{
	char name[50];
	int age;
}t5, t6;

//3���ṹ�������ʼ��
//�������ʱֱ�ӳ�ʼ����ͨ��{}
struct Teacher t7 = {"lily", 15};

//4��typedef��������
typedef struct Teacher3
{
	char name[50];
	int age;
}Teacher3;
struct Teacher3 t8;
Teacher3 t9;




int main(void)
{
	//5�����������ָ�뷨�����ṹ��
	strcpy(t9.name, "ZiJiejun");
	t9.age = 18;
	printf("%s, %d\n", t9.name, t9.age);

	//ָ�뷨
	Teacher3 *p = &t9;
	strcpy(p -> name, "ZiJiej");
	p -> age = 18;  //or (*p).age = 18;
	printf("%s, %d", p -> name, p -> age);

	printf("\n");
	system("pause");
	return 0;
}