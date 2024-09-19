#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[10000][10000], b[10000][10000], c[10000][10000], elem_c;
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	double tim;
	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r;
	
	start = clock();
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 10000)
	{
		while (j < 10000)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 10000)
	{
		while (j < 10000)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	for (i = 0; i < 10000; i++)
	{
		for (j = 0; j < 10000; j++)
		{
			elem_c = 0;
			for (r = 0; r < 10000; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	tim = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%f", tim);
	return(0);
}


