#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//定义结构体成员类型时不要直接给成员赋值
//结构体知识一个类型，还没有分配空间
//只有根据其类型定义变量时，才分配空间，有空间后才能赋值
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
	copyTeacher(&t3, &t1); //t1拷贝给t3
	printf("%s, %d\n", t3.name, t3.age);


	printf("\n");
	system("pause");
	return 0;
}