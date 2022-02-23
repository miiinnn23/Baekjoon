#include <cstdio>

int main(void) {
    int N, L;
    scanf("%d %d", &N, &L);

    int start = -1, count = 0;
    
    for(int i = L; i <= 100; i++) {
        int t = i * (i - 1) / 2;

        if((N - t) % i == 0 && (N - t) / i >= 0) {
            start = (N - t) / i;
            count = i;
            break;
        }
    }

    if(start < 0) {
        printf("%d\n", start);
        return 0;
    }
    for(int i = 0; i < count; i++) {
        printf("%d ", start + i);
    }
    printf("\n");
    return 0;
}