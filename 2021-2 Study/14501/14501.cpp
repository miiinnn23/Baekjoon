#include <cstdio>
#define MAX 16

int schedule[MAX][2];

int DP(int num);

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d %d", &schedule[i][0], &schedule[i][1]);
    }

    printf("%d\n", DP(N));

    return 0;
}

int DP(int num) {
    int budget[MAX];
    int max = 0;

    for(int i = 0; i < num; i++) {
        if(i + schedule[i][0] <= num) {
            budget[i] = schedule[i][1];
            
            for(int j = 0; j < i; j++) {
                if(j + schedule[j][0] <= i) {
                    budget[i] = (budget[i] > schedule[i][1] + budget[j] ? budget[i] : schedule[i][1] + budget[j]);
                }
            }
            max = (max > budget[i] ? max : budget[i]);
        }
    }
    return max;
}