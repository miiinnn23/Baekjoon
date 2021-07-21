#include <cstdio>
#define MOD 1000000000

long long DP(int n, int k);

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%lld\n", DP(n, k));
    return 0;
}

long long DP(int n, int k) {
    long long arr[201][201] = { 0 };
    
    for(int i = 0; i <= n; i++) {
        arr[1][i] = 1;
    }

    for(int i = 2; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            for(int m = 0; m <= j; m++) {
                arr[i][j] += arr[i - 1][m];
                arr[i][j] %= MOD;
            }
        }
    }
    return arr[k][n];
}