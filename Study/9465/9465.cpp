#include <cstdio>
#define MAX 100001

int DP(int num);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", DP(n));
    }
    return 0;
}

int DP(int num) {
    int data[2][MAX] = { 0 }; // 실제 스티커의 점수 저장
    int memo[2][MAX] = { 0 }; // 누적된 점수 합 저장

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= num; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    memo[0][1] = data[0][1];    // case 1. 1행 1열부터 시작
    memo[1][1] = data[1][1];    // case 2. 2행 1열부터 시작

    for(int i = 2; i <= num; i++) {
        memo[0][i] = data[0][i] + (memo[1][i - 1] > memo[1][i - 2] ? memo[1][i - 1] : memo[1][i - 2]);
        memo[1][i] = data[1][i] + (memo[0][i - 1] > memo[0][i - 2] ? memo[0][i - 1] : memo[0][i - 2]);
    }

    return memo[0][num] > memo[1][num] ? memo[0][num] : memo[1][num];
}