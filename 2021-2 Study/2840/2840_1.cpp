#include <cstdio>
#include <cstring>
#define MAX 25

// https://jaimemin.tistory.com/934
int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    char roulette[MAX];
    memset(roulette, '?', MAX);

    int index = 0;
    for(int i = 0; i < K; i++) {
        int pos;
        char c;
        scanf("%d %c", &pos, &c);

        pos %= N;
        if(index - pos < 0) index = index - pos + N;
        else index -= pos;

        if(roulette[index] != c && roulette[index] != '?') {
            printf("!\n");
            return 0;
        }

        roulette[index] = c;
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(roulette[i] != '?' && roulette[i] == roulette[j]) {
                printf("!\n");
                return 0;
            }
        }
    }

    for(int i = 0; i < N; i++) { // 마지막 index부터 시작
        printf("%c", roulette[(i + index) % N]);
    }
    printf("\n");

    return 0;
}