#include <cstdio>
#define MAX 64

int n;
int Monitor[MAX][MAX];

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

void division(int x, int y, int num) {
    if(num == 1) {
        printf("%d", Monitor[x][y]);
        return;
    }

    bool Zero = true, One = true;    // 모든 값이 0 또는 1인 경우
    for(int i = x; i < x + num; i++) {
        for(int j = y; j < y + num; j++) {
            if(Monitor[i][j] == 0) One = false;  // 하나라도 1이 아닌 경우
            if(Monitor[i][j] == 1) Zero = false; // 하나라도 0이 아닌 경우
        }
    }

    if(Zero) {
        printf("0");
        return;
    }
    if(One) {
        printf("1");
        return;
    }

    printf("(");
    division(x, y, num / 2);
    division(x, y + (num / 2), num / 2);
    division(x + (num / 2), y, num / 2);
    division(x + (num / 2), y + (num / 2), num / 2);
    printf(")");
}