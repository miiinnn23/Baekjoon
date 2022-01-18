#include <cstdio>
#define MAX 200000
// 당연히 시간초과나겠지
int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int school[MAX];
    int maximum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &school[i]);
        if(school[i] > maximum) {
            maximum = school[i];
        }
    }

    if(N <= 2) {
        printf("%d\n", 2 * GCD(school[0], school[1]));
        return 0;
    }

    long long int team = 0;
    for(int i = 1; i <= maximum; i++) {
        long long int count = 0;
        for(int j = 0; j < N; j++) {
            if(school[j] % i == 0) {
                count += i;
            }
        }
        if(count > team) {
            team = count;
        }
    }

    printf("%lld\n", team);

    return 0;
}