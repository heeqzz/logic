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
	} stud[5];
	int num = 5;
	for (i = 0; i < num; i++)
	{
		printf("Введите фамилию студента\n");
		scanf("%20s", &stud[i].famil);
		printf("Введите имя студента %s\n", stud[i].famil);
		scanf("%20s", &stud[i].name);
		printf("Введите номер группы студента %s %s\n", stud[i].famil, stud[i].name);
		scanf("%d", &stud[i].group);
	}
	getchar();

	for (i = 0; i < num; i++)
	{
		printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
	}
	int need_group;
	int search;
	printf("Поиск по номеру группы (введите 1) или по фамилии (введите 2)\n");
	scanf("%d", &search);
	if (search == 1) {
		printf("Введите номер необходимой группы\n");
		scanf("%d", &need_group);
		for (i = 0; i < num; i++)
		{
			if (stud[i].group == need_group) {
				printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
			}

		}
	}
	else {
		char surname[20];
		printf("Введите фамилию студента\n");
		scanf("%s", &surname);
		int res ;
		for (i = 0; i < num; i++)
		{
			res = strcmp(surname, stud[i].famil);
			if (res==0) {
				printf("Cтудент %s %s, номер группы %d \n", stud[i].famil, stud[i].name, stud[i].group);
			}
		}
	}

	getchar();
}