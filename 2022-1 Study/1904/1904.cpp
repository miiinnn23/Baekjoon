#include <cstdio>
#define MAX 1000001
#define MOD 15746

long long int fib[MAX];
int DP(int num);

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d\n", DP(N));    
    return 0;
}

int DP(int num) {
    fib[1] = 1;
    fib[2] = 2;

    for(int i = 3; i <= num; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    return fib[num];
}