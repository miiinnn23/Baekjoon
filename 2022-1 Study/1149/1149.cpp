#include <cstdio>
#define MAX 1001

int N;
int color[MAX][3];
// [i][0] : R, [i][1] : G, [i][2] : B
int DP();
int min(int a, int b) {
    return (a < b ? a : b);
}
int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &color[i][j]);
        }
    }

    printf("%d\n", DP());
    return 0;
}

int DP() {
    int sum[MAX][3];
    for(int i = 0; i < 3; i++) {
        sum[0][i] = color[0][i];
    }
    
    for(int i = 1; i < N; i++) {
        sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + color[i][0];
        sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + color[i][1];
        sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + color[i][2];
    }

    int result = min(min(sum[N - 1][0], sum[N - 1][1]), sum[N - 1][2]);

    return result;
}