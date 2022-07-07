#include <cstdio>
#define MAX 1500051

int schedule[MAX][2];
int result[MAX];

int max(int a, int b) {
    return (a > b ? a : b);
}

void DP(int num);

int main(void) {
    int N;
    scanf("%d", &N);

    DP(N);
    return 0;
}

void DP(int num) {
    int maximum = 0;
    int current = 0;

    for(int i = 1; i <= num; i++) {
        scanf("%d %d", &schedule[i][0], &schedule[i][1]);
    }

    for(int i = 1; i <= num + 1; i++) {
        current = max(current, result[i]);

        if(i + schedule[i][0] <= num + 1) {
            result[i + schedule[i][0]] = max(result[i + schedule[i][0]], current + schedule[i][1]);
            maximum = max(maximum, result[i + schedule[i][0]]);
        }
        else continue;
    }

    printf("%d\n", maximum);
}