#include <cstdio>
#include <vector>
#define MAX 12

using namespace std;

vector<int> memo(MAX, 0);
int DP(int num);

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        printf("%d\n", DP(num));
    }
    return 0;
}

int DP(int num) {
    if(num == 0) return 1;
    if(num < 3) return num;
    if(memo[num] > 0) return memo[num];

    int result = (DP(num - 1) + DP(num - 2) + DP(num - 3));
    memo[num] = result;
    return result;
}