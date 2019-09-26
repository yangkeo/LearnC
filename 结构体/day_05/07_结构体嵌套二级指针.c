#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一个导师有n个学生
typedef struct Teacher
{
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
	}
}

void print_Teacher(Teacher *q, int n1, int n2)
{
	int i = 0, j = 0;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			printf("%s, \n", q[i].stu[j]);
		}		
	}
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
#if 0
	char **name = NULL;
	//char *name[3]
	int n = 3, i = 0;
	name = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		name[i] = (char *)malloc(30);
		sprintf(name[i], "lily%d%d", i, i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%s, \n", name[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (name[i] != NULL)
		{
			free(name[i]);
			name[i] = NULL;
		}
	}

	if (name != NULL)
	{
		name = NULL;
	}
#endif

#if 0
	//1 一个导师三个学生
	Teacher t;
	//t.stu[3]

	//char *t.stu[3]   //???
	int n = 3, i = 0;
	t.stu = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		t.stu[i] = (char *)malloc(30);
		sprintf(t.stu[i], "lily%d%d", i, i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%s, \n", t.stu[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (t.stu[i] != NULL)
		{
			free(t.stu[i]);
			t.stu[i] = NULL;
		}
	}

	if (t.stu != NULL)
	{
		t.stu = NULL;
	}
#endif 

#if 0

	//2 一个导师三个学生
	Teacher *p;
	//p.stu[3]

	int i = 0, n = 3;
	p = (Teacher *)malloc(sizeof(Teacher));
	p -> stu = (char **)malloc(n * sizeof(char *)) ;
	for (i = 0; i < n; i++)
	{
		p -> stu[i] = (char *)malloc(30);
		sprintf(p->stu[i], "lily%d%d", i, i);
	}

	for (i = 0; i < n; i++)
	{
		printf("%s, \n", p->stu[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (p->stu[i] != NULL)
		{
			free(p->stu[i]);
			p->stu[i] = NULL;
		}
	}

	if (p->stu != NULL)
	{
		free(p->stu);
		p->stu = NULL;
	}
	
	if(p != NULL)
	{
		free(p);
		p = NULL;
	}

#endif
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