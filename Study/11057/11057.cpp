#include <cstdio>
#define MAX 1001

int DP(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d\n", DP(num));
    return 0;
}

int DP(int num) {
    int Step[MAX][10] = { 0 };
    for(int i = 0; i < 10; i++) {
        Step[1][i] = 1;
    }

    for(int i = 2; i <= num; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = j; k < 10; k++) {
                Step[i][j] += Step[i - 1][k] % 10007;
                Step[i][j] %= 10007;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += Step[num][i];
        sum %= 10007;
    }

    return sum;
}