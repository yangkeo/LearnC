#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//����ṹ���Ա����ʱ��Ҫֱ�Ӹ���Ա��ֵ
//�ṹ��֪ʶһ�����ͣ���û�з���ռ�
//ֻ�и��������Ͷ������ʱ���ŷ���ռ䣬�пռ����ܸ�ֵ
typedef struct Teacher
{
	char name[50];
	int age;
}Teacher;

void copyTeacher(Teacher *to, Teacher *from)
{
	*to = *from;
}

int main(void)
{
	Teacher t1 = {"lily", 24};
	Teacher t2 = t1;
	printf("%s, %d\n", t2.name, t2.age);

	Teacher t3;
	memset(&t3, 0, sizeof(t3));
	copyTeacher(&t3, &t1); //t1������t3
	printf("%s, %d\n", t3.name, t3.age);


	printf("\n");
	system("pause");
	return 0;
}