#include <cstdio>
#define MAX 64

int n;
int Monitor[MAX][MAX];

bool check(int x, int y, int num);
void division(int x, int y, int num);
int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &Monitor[i][j]);
        }
    }

    division(0, 0, n);
    printf("\n");
    return 0;
}

bool check(int x, int y, int num) {
    int k = Monitor[x][y];

    for(int i = x; i < x + num; i++) {
        for(int j = y; j < y + num; j++) {
            if(Monitor[i][j] != k) return false;
        }
    }
    return true;
}

void division(int x, int y, int num) {
    if(check(x, y, num)) {
        printf("%d", Monitor[x][y]);
    }
    else {
        int divide = num / 2;
        printf("(");
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                division(x + divide * i, y + divide * j, divide);
            }
        }
        printf(")");
    }
}