#include <cstdio>
#define MOD 1000000000
#define MAX 1000001

long long DP(int num);

int main(void) {
    int n, flag = 1;
    scanf("%d", &n);

    if(n < 0) {
        n *= -1;
        if(n % 2 == 0) flag = -1;
    }
    
    if(n == 0) flag = 0;

    printf("%d\n%lld\n", flag, DP(n));
    return 0;
}

long long DP(int num) {
    long long arr[MAX];

    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <= num; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
    }

    return arr[num] % MOD;
}