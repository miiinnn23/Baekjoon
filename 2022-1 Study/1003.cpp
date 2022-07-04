#include <cstdio>
#define MAX 41

void DP(int num);

int main(void) {
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        int num;
        scanf("%d", &num);
        DP(num);
    }
    return 0;
}

void DP(int num) {
    int count[MAX][2];
    count[0][0] = 1, count[0][1] = 0;
    count[1][0] = 0, count[1][1] = 1;

    for(int i = 2; i <= num; i++) {
        count[i][0] = count[i - 1][0] + count[i - 2][0];
        count[i][1] = count[i - 1][1] + count[i - 2][1];
    }
    printf("%d %d\n", count[num][0], count[num][1]);
}