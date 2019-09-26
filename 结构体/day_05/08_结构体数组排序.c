#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一个导师有n个学生
typedef struct Teacher
{
	int age;
	char **stu; //二维内存
}Teacher;

int create_Teacher(Teacher **p, int n1, int n2)
{
	int i = 0, j = 0;
	if (p == NULL)
	{
		return -1;
	}

	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)* n1);  //相当于  Teacher q[3];

	for (i = 0; i < n1; i++)
	{
		//(q+i)->stu  指针法  同理
		tmp[i].stu = (char **)malloc(sizeof(char *)* n2);
	}

	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			tmp[i].stu[j] = (char *)malloc(30);
		}
	}

	*p = tmp;
	return 0;
}

void write_Teacher(Teacher **p, int n1, int n2)
{
	int i = 0, j = 0;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			sprintf((*p)[i].stu[j], "lily%d%d", i, j);
		}
		(*p)[i].age = 20 + i;
	}
}

void sort_Teacher(Teacher *p, int n)
{
	if (p == NULL)
	{
		return;
	}
	int i = 0, j = 0;
	Teacher tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p[i].age < p[j].age) //降序
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

void print_Teacher(Teacher *q, int n1, int n2)
{
	int i = 0, j = 0;
	for (i = 0; i < n1; i++)
	{
		printf("p[%d].age = %d\n", i, q[i].age);
		for (j = 0; j < n2; j++)
		{
			printf("%s, \n", q[i].stu[j]);
		}
		printf("\n");
	}
	printf("\n");
}

int free_malloc(Teacher **q, int n1, int n2)
{
	int i = 0, j = 0;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if ((*q)[i].stu[j] != NULL)
			{
				free((*q)[i].stu[j]);
				(*q)[i].stu[j] = NULL;
			}
		}
	}

	for (i = 0; i < n1; i++)
	{
		if ((*q)[i].stu != NULL)
		{
			free((*q)[i].stu);
			(*q)[i].stu = NULL;
		}
	}
}

int main(void)
{

	//3 三个导师九个学生
	Teacher *q = NULL;
	int ret = 0, n1 = 3, n2 = 3, i = 0, j = 0;
	ret = create_Teacher(&q, n1, n2);
	//Teacher *q[3]
	//q[i].stu[3]
	if (ret != 0)
	{
		printf("createTeacher err: %d", ret);
		system("pause");
		return 0;
	}

	write_Teacher(&q, n1, n2);
	printf("前\n");
	print_Teacher(q, n1, n2);	
	sort_Teacher(q, n1);
	printf("后\n");
	print_Teacher(q, n1, n2);
	free_malloc(&q, n1, n2);

	if (q != NULL)
	{
		free(q);
		q = NULL;
	}


	printf("\n");
	system("pause");
	return 0;
}