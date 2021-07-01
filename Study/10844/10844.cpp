#include <cstdio>
#define MAX 101

long DP(int num);
long Step[MAX][10] = { 0 };

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%ld\n", DP(n));
    return 0;
}

long DP(int num) {
    for(int i = 1; i < 10; i++) {
        Step[1][i] = 1;
    }
    
    for(int i = 2; i <= num; i++) {
        Step[i][0] = Step[i - 1][1] % 1000000000;
        for(int j = 1; j < 9; j++) {
            Step[i][j] = (Step[i - 1][j - 1] + Step[i - 1][j + 1]) % 1000000000;
        }
        Step[i][9] = Step[i - 1][8] % 1000000000;
    }

    long sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += Step[num][i];
        sum %= 1000000000;
    }

    return sum;
}