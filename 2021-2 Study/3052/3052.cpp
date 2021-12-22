#include <cstdio>

int main(void) {
    int check[42] = { 0 };
    int count = 0;

    for(int i = 0; i < 10; i++) {
        int num;
        scanf("%d", &num);
        check[num % 42]++;
    }

    for(int i = 0; i < 42; i++) {
        if(check[i] > 0) count++;
    }
    printf("%d\n", count);
    return 0;
}