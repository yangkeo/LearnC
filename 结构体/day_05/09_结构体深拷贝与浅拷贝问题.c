#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一个导师有n个学生
typedef struct Teacher
{
	char *name;
	int age;	 
}Teacher;

//浅拷贝条件：
//结构体中嵌套指针，而且动态分配空间
//同类结构体变量赋值
//不同结构体成员指针变量指向同一块内存

int main(void)
{
	Teacher t1;
	t1.name = (char *)malloc(30);
	strcpy(t1.name, "lily");
	t1.age = 20;

	Teacher t2 = t1;
    //深拷贝，人为增加内容，重新拷贝一下
	t2.name = (char *)malloc(30);  //与t1完全独立，需要再释放。深拷贝在C语言中意义不大
	strcpy(t2.name, t1.name);

	printf("[t2]%s, %d\n", t2.name, t2.age);

	if (t1.name != NULL)  // 浅拷贝， 只释放最初malloc的指针就好
	{
		free(t1.name);
		t1.name = NULL;
	}

	/*if (t2.name != NULL)    //会崩
	{
		free(t2.name);    
		t2.name = NULL;
	}*/


	printf("\n");
	system("pause");
	return 0;
}