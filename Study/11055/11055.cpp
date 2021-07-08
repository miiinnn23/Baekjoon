#include <cstdio>
#define MAX 1001

int DP(int num);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    int A[MAX] = { 0 };
    int memo[MAX] = { 0 };
    int sum = 0;

    for(int i = 1; i <= num; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 1; i <= num; i++) {
        memo[i] = A[i];
        for(int j = 1; j < i; j++) {
            if(A[i] > A[j] && memo[i] < memo[j] + A[i]) {
                memo[i] = memo[j] + A[i];
            }
        }
        sum = (sum > memo[i] ? sum : memo[i]);
    }

    return sum;
}