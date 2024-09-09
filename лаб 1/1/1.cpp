#include <stdio.h>
#include <limits.h>
int main()
{
    int max = INT_MIN, min = INT_MAX;
    int a[10] = { 30,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 10; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("min= %d, max= %d difference=%d", min, max, max - min);
    return(0);
}
