#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M;
    int i, j, count;

    scanf("%d", &N);
    int* num = (int *)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    scanf("%d", &M);
    int input;
    for(i = 0; i < M; i++) {
        count = 0;
        scanf("%d", &input);
        for(j = 0; j < N; j++) {
            if(input == num[j]) {
                count++;
            }
        }
        printf("%d ", count);
    }
    printf("\n");

    free(num);
    return 0;
}