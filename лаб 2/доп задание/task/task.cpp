#include <stdio.h>
#include <time.h>
#include <Windows.h>

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
int compare(const void* x1, const void* x2) /*функция сравнения элементов массива*/
{
	return (*(int*)x1 - *(int*)x2); /* <0 elem1 меньше elem2, =0 elem1 эквивалентен elem2, >0 elem1 больше elem2*/
}
int main() {
	const int count = 100000;
	double tim1, tim2, tim3, tim11, tim21, tim31, tim12, tim22, tim32, tim13, tim23, tim33;
	clock_t start, end; // объявляем переменные для определения времени выполнени
	/*int b[count], c[count], d[count];*/
	//vosrast-ubuv
	int* g = (int*)malloc(count * sizeof(int));
	int* b = (int*)malloc(count * sizeof(int));
	int* c = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count / 2; i++) {
		b[i] = i;
	}
	for (int i = count / 2; i < count; i++) {
		b[i] = b[49999] - 1;
	}
	for (int i = 0; i < count; i++) {
		c[i] = b[i];
	}
	for (int i = 0; i < count; i++) {
		g[i] = b[i];
	}
	//vosrast
	int* g1 = (int*)malloc(count * sizeof(int));
	int* b1 = (int*)malloc(count * sizeof(int));
	int* c1 = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++) {
		b1[i] = i;
	}
	for (int i = 0; i < count; i++) {
		c1[i] = b[i];
	}
	for (int i = 0; i < count; i++) {
		g1[i] = b[i];
	}
	//ubyv
	int* g2 = (int*)malloc(count * sizeof(int));
	int* b2 = (int*)malloc(count * sizeof(int));
	int* c2 = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++) {
		b2[i] = 1000000 - i;
	}
	for (int i = 0; i < count; i++) {
		c2[i] = b[i];
	}
	for (int i = 0; i < count; i++) {
		g2[i] = b[i];
	}
	//rand
	int* g3 = (int*)malloc(count * sizeof(int));
	int* b3 = (int*)malloc(count * sizeof(int));
	int* c3 = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++) {
		b3[i] = rand() % 100000 - 0;
	}
	for (int i = 0; i < count; i++) {
		c3[i] = b[i];
	}
	for (int i = 0; i < count; i++) {
		g3[i] = b[i];
	}
	//SHELL vos-uby
	start = clock();
	shell(b, count);
	end = clock();
	tim1 = (double)(end - start) / CLOCKS_PER_SEC;
	//vos
	start = clock();
	shell(b1, count);
	end = clock();
	tim11 = (double)(end - start) / CLOCKS_PER_SEC;
	//uby
	start = clock();
	shell(b2, count);
	end = clock();
	tim12 = (double)(end - start) / CLOCKS_PER_SEC;
	//rand
	start = clock();
	shell(b3, count);
	end = clock();
	tim13 = (double)(end - start) / CLOCKS_PER_SEC;
	//QS
	start = clock();
	qs(c, 0, count - 1);
	end = clock();
	tim2 = (double)(end - start) / CLOCKS_PER_SEC;
	//vos
	start = clock();
	qs(c1, 0, count - 1);
	end = clock();
	tim21 = (double)(end - start) / CLOCKS_PER_SEC;
	//uby
	start = clock();
	qs(c2, 0, count - 1);
	end = clock();
	tim22 = (double)(end - start) / CLOCKS_PER_SEC;
	//rand
	start = clock();
	qs(c3, 0, count - 1);
	end = clock();
	tim23 = (double)(end - start) / CLOCKS_PER_SEC;
	//QSORT
	start = clock();
	qsort(g, count, sizeof(int), compare);
	end = clock();
	tim3 = (double)(end - start) / CLOCKS_PER_SEC;
	//vos
	start = clock();
	qsort(g1, count, sizeof(int), compare);
	end = clock();
	tim31 = (double)(end - start) / CLOCKS_PER_SEC;
	//uby
	start = clock();
	qsort(g2, count, sizeof(int), compare);
	end = clock();
	tim32 = (double)(end - start) / CLOCKS_PER_SEC;
	//rand
	start = clock();
	qsort(g3, count, sizeof(int), compare);
	end = clock();
	tim33 = (double)(end - start) / CLOCKS_PER_SEC;
	printf("sort vosr-ub vosr uby rand \n");
	printf("Shell %lf %lf %lf %lf \n", tim1, tim11, tim12, tim13);
	printf("  qs  %lf %lf %lf %lf \n", tim2, tim21, tim22, tim23);
	printf("qsort %lf %lf %lf %lf \n", tim3, tim31, tim32, tim33);
	getchar();
}