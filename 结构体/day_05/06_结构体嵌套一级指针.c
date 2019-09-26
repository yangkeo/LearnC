#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char *name;
	int age;
}Teacher;

Teacher *getMen(int n)
{
	Teacher *q = NULL;
	q = (Teacher *)malloc(3 * sizeof(Teacher));
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		q[i].name = (char *)malloc(sizeof(char *));
		sprintf(q[i].name, "ZiJiejun%d%d%d", i, i, i);
		q[i].age = 22 + i;
	}
	return q;
}

void showTeacher(Teacher *p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("µÚ%d¸öname = %s, age = %d\n", i, p[i].name, p[i].age);
	}
} 

void freemalloc(Teacher *p, int n)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (p[i].name != NULL)
		{
			free(p[i].name);
			p[i].name = NULL;
		}
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

int main(void)
{
#if 0
	char *name = NULL;
	name = (char *)malloc(30);
	strcpy(name, "lily");
	printf("name = %s\n", name);
	if (name != NULL)
	{
		free(name);
		name = NULL;
	}
#endif

#if 0
	//1
	Teacher t;
	t.name = (char *)malloc(30);
	strcpy(t.name, "lily");
	t.age = 22;
	printf("name = %s, age = %d", t.name, t.age);
	if (t.name != NULL)
	{
		free(t.name);
		t.name = NULL;
	}
#endif

#if 0

	//2
	Teacher *p = NULL;
	p = (Teacher *)malloc(sizeof(Teacher));
	p -> name = (char *)malloc(30);
	strcpy(p->name, "zjj");
	p -> age = 22;
	printf("name = %s, age = %d", p->name, p -> age);
	if (p->name != NULL)
	{
		free(p->name);
		p->name = NULL;
	}

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
#endif
	

	//3
	Teacher *q = getMen(3);

	showTeacher(q, 3);
	freemalloc(q, 3);
	q = NULL;

	
	


	printf("\n");
	system("pause");
	return 0;
}