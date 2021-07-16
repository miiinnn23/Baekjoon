#include <cstdio>

long long GCD(long long a, long long b);

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long result = GCD(a, b);
    for(long long i = 0; i < result; i++) {
        printf("1");
    }
    printf("\n");
    return 0;
}

long long GCD(long long a, long long b) {
    return b ? GCD(b, a % b) : a;
}