#include <cstdio>
#define MAX 1000001
#define MOD 1000000009

long long int sum[MAX];
int DP(int num);

int main(void) {
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        printf("%d\n", DP(N));
    }
    return 0;
}

int DP(int num) {
    sum[1] = 1;
    
    for(int i = 2; i <= num; i++) {
        sum[i] = (sum[i - 1] + sum[i - 2] + sum[i - 3]) % MOD;
        if(i == 2) {
            sum[i] += 1;
        }
        if(i == 3) {
            sum[i] += 1;
        }
    }

    return (sum[num] % MOD);
}