#include <cstdio>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> memo(MAX, 0);
int DP(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d\n", DP(num));
    return 0;
}

int DP(int num) {
    if(num <= 2) return num;
    if(memo[num] > 0) return memo[num];

    int result = (DP(num - 1) + DP(num - 2)) % 10007;
    memo[num] = result;
    return result;
}