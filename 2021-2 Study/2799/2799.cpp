#include <cstdio>
#define MAX 501

char building[MAX][MAX];
int window[5] = { 0 };

void counting(int i, int j);

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);

    for(int i = 0; i <= 5 * M; i++) {
        scanf("%s", building[i]);
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            counting(i, j);
        }
    }

    for(int i = 0; i < 5; i++) {
        printf("%d ", window[i]);
    }
    printf("\n");
    return 0;
}

void counting(int i, int j) {
    int count = 0;
    for(int a = 1; a <= 4; a++) {
        for(int b = 1; b <= 4; b++) {
            if(building[i * 5 + a][j * 5 + b] == '*') {
                count++;
            }
        }
    }
    window[count / 4]++;
}