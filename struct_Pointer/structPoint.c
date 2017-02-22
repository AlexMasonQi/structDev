#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char *Name;
	char **strName;
	int Age;
	int ID;
}Teacher;

int creatMem(Teacher **mem, int num)
{
	int i, j = 0;
	Teacher *temp = (Teacher *)malloc(sizeof(Teacher) * num);
	if (temp == NULL)
	{
		return -1;
		exit(0);
	}
	memset(temp, 0, sizeof(Teacher) * num);
	for (i = 0; i < num; i++)
	{
		//套一级指针
		temp[i].Name = (char *)malloc(sizeof(char) * 64);

		//套二级指针
		char **p = (char **)malloc(sizeof(char *) * num);
		for (j = 0; j < num; j++)
		{
			p[j] = (char *)malloc(sizeof(char) * 64);
		}
		temp[i].strName = p;
	}
	*mem = temp;
	return 0;
}

void freeMem(Teacher *mem, int num)
{
	int i, j = 0;
	if (mem == NULL)
	{
		return;
		exit(0);
	}
	for (i = 0; i < num; i++)
	{
		//释放一级指针
		if (mem[i].Name != NULL)
		{
			free(mem[i].Name);
			mem[i].Name = NULL;
		}
		
		//释放二级指针
		char **temp = mem[i].strName;
		for (j = 0; j < num; j++)
		{
			if (temp[j] != NULL)
			{
				free(temp[j]);
				temp[j] = NULL;
			}
		}
		if (temp != NULL)
		{
			free(temp);
			temp == NULL;
		}
	}
	free(mem);
}

int sortAge(Teacher *sortmem, int num)
{
	int i, j = 0;
	Teacher tmp;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (sortmem[i].Age > sortmem[j].Age)
			{
				tmp = sortmem[i];
				sortmem[i] = sortmem[j];
				sortmem[j] = tmp;
			}
		}
	}
}

int main()
{
	Teacher *buf = NULL;
	int i, j = 0;
	int num = 3;
	creatMem(&buf, num);
	for (i = 0; i < num; i++)
	{
		printf("\nPlease input your name:");
		scanf("%s", buf[i].Name);
		for (j = 0; j < num; j++)
		{
			printf("\nPlease input the strname:");
			scanf("%s", buf[i].strName[j]);
		}
		printf("\nPlease input your age:");
		scanf("%d", &(buf[i].Age));
		printf("\nPlease input your ID:");
		scanf("%d", &(buf[i].ID));	
	}
	sortAge(buf, num);
	for (i = 0; i < num; i++)
	{
		printf("%d\t", buf[i].Age);
	}
	printf("\n");
	freeMem(buf,num);
	
	system("pause");
	return 0;
}