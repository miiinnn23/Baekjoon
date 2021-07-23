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
    int length = 0;

    for(int i = 1; i <= num; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 1; i <= num; i++) {
        memo[i] = 1;
        for(int j = 1; j < i; j++) {
            if(A[i] > A[j]) {
                // memo[i] = (memo[i] > memo[j] ? memo[i] : memo[i] + 1);
                memo[i] = (memo[i] > memo[j] ? memo[i] : memo[j] + 1);
            }
        }
        length = (length > memo[i] ? length : memo[i]);
    }

    return length;
}