#include <cstdio>

int GCD(int a, int b);
int LCM(int a, int b);

int main(void) {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCM(a, b));
    }
    return 0;
}

int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}