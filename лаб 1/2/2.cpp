#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int w, v[10];
	for (int i = 0; i < 10; i++) {
		w = rand() % 100;
		v[i] = w;
		printf("%d ", v[i]);
	}
	getchar();
}

