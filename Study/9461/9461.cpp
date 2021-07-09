#include <cstdio>
#include <vector>
#define MAX 101

using namespace std;
long DP(int num);
vector<long> memo(MAX, 0);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%ld\n", DP(n));
    }
    return 0;
}

long DP(int num) {
    memo[1] = memo[2] = memo[3] = 1;
    memo[4] = memo[5] = 2;

    for(int i = 6; i <= num; i++) {
        memo[i] = memo[i - 1] + memo[i - 5];
    }

    return memo[num];
}