#include <cstdio>
#define MAX 91

long long DP(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%lld\n", DP(num));
    return 0;
}

long long DP(int num) {
    long long Step[MAX] = { 0 };
    Step[1] = 1;

    for(int i = 2; i <= num; i++) {
        Step[i] = Step[i - 1] + Step[i - 2];
    }

    return Step[num];
}