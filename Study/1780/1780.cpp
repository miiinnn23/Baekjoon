#include <cstdio>
#define MAX 2188
// https://chanhuiseok.github.io/posts/baek-13/
int N;
int paper[MAX][MAX];
int count[3];

bool check(int x, int y, int num);
void division(int x, int y, int num);

int main(void) {
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    division(0, 0, N);

    for(int i = 0; i < 3; i++) {
        printf("%d\n", count[i]);
    }
    return 0;
}

bool check(int x, int y, int num) {
    int k = paper[x][y];

    for(int i = x; i < x + num; i++) {
        for(int j = y; j < y + num; j++) {
            if(paper[i][j] != k) return false;
        }
    }
    return true;
}

void division(int x, int y, int num) {
    if(check(x, y, num)) {
        count[paper[x][y] + 1]++;
    }
    else {
        int divide = num / 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                division(x + divide * i, y + divide * j, divide);
            }
        }
    }
}