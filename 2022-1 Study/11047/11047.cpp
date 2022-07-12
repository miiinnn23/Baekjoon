#include <cstdio>
#define MAX 10

int coin[MAX];
int N, K;

void Calc();

int main(void) {
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    Calc();
    return 0;
}

void Calc() {
    int count = 0;

    int temp = K;
    for(int i = N - 1; i >= 0; i--) {
        if(temp < coin[i]) continue;
        else {
            int j = temp / coin[i];
            count += j;
            temp -= j * coin[i];
        }

        if(temp == 0) break;
    }

    printf("%d\n", count);
}