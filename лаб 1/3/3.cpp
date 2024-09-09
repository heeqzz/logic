#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int w, *v, n;
	printf("enter n\n");
	scanf_s("%d", &n);
	getchar();
	v=(int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		w = rand() % 100;
		v[i] = w;
		printf("%d ", v[i]);
	}
	free(v);
	getchar();
}
