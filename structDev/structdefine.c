#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char Name[64];
	int Age;
	int ID;
}Teacher;

void creatMem(Teacher **mem, int num)
{
	//int i = 0;
	Teacher *tmp = (Teacher *)malloc(sizeof(Teacher) * num);
	if (tmp == NULL)
	{
		return NULL;
	}
	*mem = tmp;
}

//通过Age成员比较大小然后整体搬运（互换）结构体的成员元素
void sortTeacher(Teacher *Array, int num)
{
	int i, j = 0;
	Teacher temp;
	for(i=0;i<num;i++)
		for (j = i + 1; j < num; j++)
		{
			if (Array[i].Age > Array[j].Age)
			{
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
}

void freeMem(Teacher *mem, int num)
{
	if (mem != NULL)
	{
		free(mem);
		mem = NULL;
	}
}

int main()
{
	//Teacher bufArr[3];
	int i = 0;
	int num = 3;
	Teacher *bufArr = NULL;
	creatMem(&bufArr, num);
	for (i = 0; i < num; i++)
	{
		printf("\nPlease input the age:");
		scanf("%d", &(bufArr[i].Age));//&((bufArr+i)->Age)=&(bufArr[i].Age)
	}
	sortTeacher(bufArr, num);
	printf("After sorting...\n");
	for (i = 0; i < num; i++)
	{
		printf("%d\t", (bufArr + i)->Age);
	}
	printf("\n");
	freeMem(bufArr, num);

	system("pause");
	return 0;
}