#include <cstdio>
#define MAX 100001
#define MOD 9901

int DP(int num);
int lion[MAX];

int main(void) {
    int N;
    scanf("%d", &N);

    printf("%d\n", DP(N));
    return 0;
}

int DP(int num) {
    lion[0] = 1;
    lion[1] = 3;
    
    for(int i = 2; i <= num; i++) {
        lion[i] = (lion[i - 2] + lion[i - 1] * 2) % MOD;
    }

    return lion[num];
}