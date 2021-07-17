#include <cstdio>

int main(void) {
    int n, div;
    scanf("%d", &n);

    div = n;
    for(int i = 2; i * i <= n; i++) {
        while(div % i == 0) {
            printf("%d\n", i);
            div /= i;
        }
    }

    if(div != 1) printf("%d\n", div);
    return 0;
}