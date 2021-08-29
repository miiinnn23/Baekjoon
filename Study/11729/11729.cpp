#include <cstdio>
#include <cmath>

void Hanoi(int num, int from, int to, int pass);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (int)pow(2, n) - 1);
    Hanoi(n, 1, 3, 2);
    return 0;
}

void Hanoi(int num, int from, int to, int pass) {
    if(num == 1) {
        printf("%d %d\n", from, to);
    }
    else {
        Hanoi(num - 1, from, pass, to);
        printf("%d %d\n", from, to);
        Hanoi(num - 1, pass, to, from);
    }
}