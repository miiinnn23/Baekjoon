#include <cstdio>
#define MAX 1001

int N;
int color[MAX][3];
// [i][0] : R, [i][1] : G, [i][2] : B
int DP();

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
    int sum[MAX][2];
    
    int min = color[0][0];
    int c1 = 0, c2 = 0;

    for(int i = 1; i < 3; i++) {
        if(color[0][i] < min) {
            min = color[0][i];
            c1 = i;
        }
    }

    sum[0][0] = min;
    sum[0][1] = c1;

    int result[2];
    
    for(int i = 1; i < N; i++) {
        if(color[i][(c1 + 1) % 3] < color[i][(c1 + 2) % 3]) {
            result[0] = sum[i - 1][0] + color[i][(c1 + 1) % 3];
            c1 = (c1 + 1) % 3;
        }
        else {
            result[0] = sum[i - 1][0] + color[i][(c1 + 2) % 3];
            c1 = (c1 + 2) % 3;
        }

        c2 = 3 - (sum[i - 2][1] + sum[i - 1][1]);
        if(color[i][(c2 + 1) % 3] < color[i][(c2 + 2) % 3]) {
            result[1] = sum[i - 2][0] + color[i - 1][c2] + color[i][(c2 + 1) % 3];
            c2 = (c2 + 1) % 3;
        }
        else {
            result[1] = sum[i - 2][0] + color[i - 1][c2] + color[i][(c2 + 2) % 3];
            c2 = (c2 + 2) % 3;
        }

        if(result[0] > result[1]) {
            sum[i - 1][0] = result[1] - color[i][c2];
            sum[i - 1][1] = 3 - (sum[i - 2][1] + sum[i - 1][1]);

            sum[i][0] = result[1];
            sum[i][1] = c2;
        }
        else {
            sum[i][0] = result[0];
            sum[i][1] = c1;
        }
    }

    return sum[N - 1][0];
}