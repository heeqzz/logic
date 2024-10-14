
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node
{
	char inf[256]; // полезная информация
	int priority; // приоритет элемента
	struct node* next; // ссылка на следующий элемент
};

// Указатели на начало и конец списка
struct node* head = NULL, * last = NULL;
int flag = -1;

void push_priority(void), review(void), del(char* name);
char str[256];
struct node* find(int priority);
struct node* get_struct(void);

// Функция для создания нового узла с приоритетом
struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];
	int t;
	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	printf("Введите приоритет объекта: \n");
	scanf("%d", &p->priority);

	p->next = NULL;
	return p;
}

// Функция для добавления элемента с приоритетом в список
void push_priority(void)
{
	struct node* p = NULL;
	p = get_struct();

	if (p == NULL) return; // Если не удалось создать узел

	// Если список пуст
	if (head == NULL)
	{
		head = p;
		last = p;
	}
	else
	{
		// Если элемент имеет наименьший приоритет, вставляем его в начало
		if (p->priority < head->priority)
		{
			p->next = head;
			head = p;
		}
		else
		{
			struct node* current = head;
			// Ищем место для вставки в зависимости от приоритета
			while (current->next != NULL && current->next->priority <= p->priority)
			{
				current = current->next;
			}
			p->next = current->next;
			current->next = p;

			// Если вставляем в конец
			if (p->next == NULL)
				last = p;
		}
	}
}

/* Просмотр содержимого списка, отсортированного по приоритету */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
		return;
	}
	printf("Список элементов по приоритету:\n");
	while (struc)
	{
		printf("%s (Приоритет: %d)\n", struc->inf, struc->priority);
		struc = struc->next;
	}
	printf("\n");
}

// Поиск элемента с заданным приоритетом
struct node* find(int priority)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
		return NULL;
	}
	while (struc)
	{
		if (struc->priority == priority)
		{
			printf("Найден элемент: %s (Приоритет: %d)\n", struc->inf, struc->priority);
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент с заданным приоритетом не найден\n");
	return NULL;
}

// Удаление элемента из списка
void del(char* name)
{
	struct node* struc = head;
	struct node* prev = NULL; // Указатель на предшествующий элемент

	if (head == NULL)
	{
		printf("Список пуст\n");
		return;
	}

	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			if (prev == NULL)
			{
				head = struc->next;
			}
			else
			{
				prev->next = struc->next;
			}

			if (struc == last)
			{
				last = prev;
			}

			free(struc);
			printf("Элемент удалён\n");
			return;
		}
		prev = struc;
		struc = struc->next;
	}
	printf("Элемент не найден\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	while (flag != 5) {
		system("cls");
		printf("1. Добавить элемент с приоритетом\n");
		printf("2. Удалить элемент\n");
		printf("3. Найти элемент по приоритету\n");
		printf("4. Показать список\n");
		printf("5.Выйти\n");
			scanf("%d", &flag);

		if (flag == 1) {
			system("cls");
			push_priority();
		}
		else if (flag == 2) {
			system("cls");
			printf("Введите название нужного элемента: ");
			scanf("%s", str);
			del(str);
		}
		else if (flag == 3) {
			system("cls");
			int priority;
			printf("Введите приоритет для поиска: ");
			scanf("%d", &priority);
			find(priority);
			printf("\n Возвращение на главную");
			getchar();
			getchar();
		}
		else if (flag == 4) {
			system("cls");
			review();
			printf("\n Возвращение на главную");
			getchar();
			getchar();
		}
	}

	return 0;
}