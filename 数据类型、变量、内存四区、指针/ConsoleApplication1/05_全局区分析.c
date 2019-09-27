#include"stdio.h"
#include"stdlib.h"
#include"string.h"

char *get_str1()
{
	char *p = "abcdef";  //存在于文字常量区（全局区-指的是abcdef），文字常量区程序结束后才会释放

	return p;
}

char *get_str2()
{
	char *q = "abcdef";  //存在于文字常量区（全局区-指的是abcdef）

	return q;
}


int main(void)
{
	//这俩变量在栈区（程序局部变量）
	char *p = NULL;
	char *q = NULL;

	//%s:  指针指向内存区域的内容, ％s用来输出一个字符串
	//%d： 打印p本身的值
	p = get_str1();
	printf("p = %s, p = %d\n",p, p);  //01
	q = get_str2();
	printf("q = %s, q = %d",q, q);  //02  01与02输出地址相同！？因为p与q所赋值的内容
                                    // 相同，因此编译器为节省空间会使p、q同时指向该内容的地址
	printf("\n");
	system("pause");
	return 0;
	
}