#include <cstdio>

int main(void) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int result = A * B * C;
    int division = result;
    int array[10] = { 0 };

    while(division > 0) {
        int mod = division % 10;
        array[mod]++;
        division /= 10;
    }

    for(int i = 0; i < 10; i++) {
        printf("%d\n", array[i]);
    }
    return 0;
}