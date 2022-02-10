#include <cstdio>
#define MAX 501

int triangle[MAX][MAX];
int DP(int num);

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    int result = 0;
    
    for(int i = 0; i < num; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
            }
            else if(j == i) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
            }
            else {
                triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
            }

            result = max(result, triangle[i][j]);
        }
    }

    return result;
}