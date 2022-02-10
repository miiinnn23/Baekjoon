#include <cstdio>
#define MAX 1000001

int DP(int num);
int min(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    int memo[MAX];

    for(int i = 2; i <= num; i++) {
        memo[i] = memo[i - 1] + 1;

        if(i % 3 == 0) {
            memo[i] = min(memo[i], memo[i / 3] + 1);
        }
        if(i % 2 == 0) {
            memo[i] = min(memo[i], memo[i / 2] + 1);
        }
    }

    return memo[num];
}