#include <cstdio>
#include <vector>
#define MAX 1000001

using namespace std;

vector<int> memo(MAX, -1);
int DP(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d\n", DP(num));
    return 0;
}

int DP(int num) {
    if(num == 1) return 0;
    if(memo[num] != -1) {
        return memo[num];
    }

    memo[num] = DP(num - 1) + 1;

    if(num % 3 == 0) {
        memo[num] = (DP(num / 3) + 1) < memo[num] ? DP(num / 3) + 1 : memo[num];
    }
    if (num % 2 == 0) {
        memo[num] = (DP(num / 2) + 1) < memo[num] ? DP(num / 2) + 1 : memo[num];
    }
    return memo[num];
}