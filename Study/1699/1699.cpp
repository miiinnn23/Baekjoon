#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int DP(int num);
int min(int a, int b) { return a < b ? a : b; }

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}
// 틀린풀이 - 무작정 큰 수 부터 빼면 안됨!(반례 - 43(25 + 9 + 9))
// int DP(int num) {
//     vector<int> memo(num + 1, 0);
//     memo[1] = 1;
//     int j = 2;

//     for(int i = 2; i <= num; i++) {
//         int temp = (int)(sqrt(i));
//         if(i == j * j) {
//             j++;
//             memo[i] = 1;
//             continue;
//         }
//         memo[i] = memo[temp * temp] + memo[i - temp * temp];
//     }

//     return memo[num];
// }

int DP(int num) {
    vector<int> D(num + 1, 0);
    for(int i = 1; i <= num; i++) {
        D[i] = i;
    }

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j * j <= i; j++) {
            D[i] = min(D[i], D[i - j * j] + 1);
        }
    }

    return D[num];
}