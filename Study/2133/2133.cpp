#include <cstdio>
#include <vector>
#define MAX 31

using namespace std;
int DP(int num);
vector<int> memo(MAX, 0);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    memo[0] = 1;
    memo[2] = 3;

    for(int i = 4; i <= num; i++) {
        memo[i] += memo[i - 2] * memo[2];
        for(int j = 4; j <= i; j += 2) {
            memo[i] += memo[i - j] * 2;
        }
    }

    return memo[num];
}