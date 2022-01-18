#include <cstdio>
#define MAX 2000001

long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}

int school[MAX] = { 0 };

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        school[temp]++;
    }

    long long int team = 0;
    for(int i = 1; i <= MAX; i++) {
        long long int count = 0;
        for(int j = 1; j * i <= MAX; j++) {
            count += school[i * j];
        }
        if(count < 2) continue;
        team = max(team, count * i);
    }

    printf("%lld\n", team);
    return 0;
}