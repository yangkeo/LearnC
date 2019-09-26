#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
功能：1、把数组p1的字符串取出来
2、把二维数组buf2的字符取出来
3、上面的字符串放在p3, p3是在堆区分配的二维内存
4、对p3中字符串进行排序，通过 strcmp()进行排序
参数：
p1：指针数组首地址，char *p1[] = { "aa", "ccccccc", "bbbbbb" };
len1：p1元素个数
buf2：二维数组首元素地址，buf2[10][30] = { "111111", "3333333", "222222" };
len2: buf2字符串行数
p3：二级指针的地址，需要再函数内分配二维内存，保存p1和buf2的字符串，还需要排序
len3：保存p3中字符串个数
*/

/*
1、结构体类型定义
2、结构体变量定义
3、结构体变量初始化
4、typedef改类型名
5、点运算符和指针法操作结构体
6、结构体也是一种数据类型，复合类型，自定义类型
*/

//struct 关键字
//struct Tescher合在一起才是类型
//{}后面有分号
struct Teacher
{
	char name[50];
	int age;
};

//2、结构体变量定义
//1、先定义类型再定义变量（常用）
struct Teacher t1; //全局变量

//2、定义类型的同时定义变量
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

//3、结构体变量初始化
//定义变量时直接初始化，通过{}
struct Teacher t7 = {"lily", 15};

//4、typedef改类型名
typedef struct Teacher3
{
	char name[50];
	int age;
}Teacher3;
struct Teacher3 t8;
Teacher3 t9;




int main(void)
{
	//5、点运算符和指针法操作结构体
	strcpy(t9.name, "ZiJiejun");
	t9.age = 18;
	printf("%s, %d\n", t9.name, t9.age);

	//指针法
	Teacher3 *p = &t9;
	strcpy(p -> name, "ZiJiej");
	p -> age = 18;  //or (*p).age = 18;
	printf("%s, %d", p -> name, p -> age);

	printf("\n");
	system("pause");
	return 0;
}