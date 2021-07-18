#include <cstdio>

int main(void) {
    int n;
    scanf("%d", &n);

    int count = 0;
    
    for(int i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    printf("%d\n", count);
    return 0;
}