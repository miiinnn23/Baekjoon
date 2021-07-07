#include <cstdio>
#define MAX 10003

int DP(int num);
int max(int num1, int num2) { return num1 > num2 ? num1 : num2; }

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    int wine[MAX] = { 0 };
    int memo[MAX] = { 0 };

    for(int i = 3; i < (num + 3); i++) {
        scanf("%d", &wine[i]);
    }
    
    for(int i = 3; i < (num + 3); i++) {
        memo[i] = max(memo[i - 2] + wine[i], memo[i - 3] + wine[i - 1] + wine[i]);
        memo[i] = max(memo[i - 1], memo[i]);
    }

    return memo[num + 2];
}