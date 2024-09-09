#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int w, v[5][5], n = 5, sum[5]{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			w = rand() % 100;
			v[i][j] = w;
			printf("%d     ", v[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 5; i++) {
			sum[j] += v[i][j];

		}
	}
	
	for (int j = 0; j < n; j++) {
		printf("%d    ", sum[j]);
	}
	
	getchar();
}
