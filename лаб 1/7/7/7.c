#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int w,*v, n;
	printf("enter n\n");
	scanf("%d", &n);
	getchar();
	 v = (int*)malloc( n *n* sizeof(int));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			w =  +rand() % 71 - 20;
			*(v + i*n +j) = w;
			printf("%d ", *(v + i * n + j));
		}
		printf("\n");
	}
	int scet = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (*(v + i * n + j) % 3 == 0) {
				scet += 1;
			}
		}
	}
	printf("summa = %d", scet);
	free(v);
	getchar();
}