#include <cstdio>
#define MAX 41

int cinema[MAX];
int vip[MAX];

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    cinema[0] = 1;
    cinema[1] = 1;

    for(int i = 2; i < MAX; i++) {
        cinema[i] = cinema[i - 1] + cinema[i - 2];
    }

    int result = 1;
    for(int i = 1; i <= M; i++) {
        scanf("%d", &vip[i]);
        result *= cinema[vip[i] - vip[i - 1] - 1];
    }
    result *= cinema[N - vip[M]];

    printf("%d\n", result);
    return 0;
}