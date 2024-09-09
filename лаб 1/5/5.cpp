#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int   main()
{
	setlocale(LC_ALL, "Rus");
	int i;
	struct student
	{
		char famil[20];
		char name[20];
		int group;
	} stud[3];

	for (i = 0; i < 3; i++)
	{
		printf("Введите фамилию студента\n"); scanf("%20s", &stud[i].famil);
		printf("Введите имя студента %s\n", stud[i].famil); scanf("%20s", &stud[i].name);
		printf("Введите номер группы студента %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].group);
	}
	getchar();
	
	for (i = 0; i < 3; i++)
	{
		printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
	}
	int need_group;
	printf("Введите номер необходимой группы\n");
	scanf("%d", &need_group);
	for (i = 0; i < 3; i++)
	{
		if (stud[i].group==need_group) {
			printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
		}
		
	}
	getchar();
}
