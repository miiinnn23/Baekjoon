#include <cstdio>
#define MAX 13

void DFS(int start, int depth);
int k;
int lotto[MAX];
int print[MAX];

int main(void) {
    while(true) {
        scanf("%d", &k);

        if(k == 0) break;
        for(int i = 0; i < k; i++) {
            scanf("%d", &lotto[i]);
        }

        DFS(0, 0);
        printf("\n");
    }
    return 0;
}

void DFS(int start, int depth) {
    if(depth == 6) {
        for(int i = 0; i < 6; i++) {
            printf("%d ", print[i]);
        }
        printf("\n");
        return;
    }

    for(int i = start; i < k; i++) {
        print[depth] = lotto[i];
        DFS(i + 1, depth + 1);
    }
}