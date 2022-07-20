#include <cstdio>
#define MAX 21

int N, S;
int count = 0;
int sequence[MAX];

void DFS(int num, int sum);

int main(void) {
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }

    DFS(0, 0);
    printf("%d\n", count);
    return 0;
}

void DFS(int num, int sum) {
    if(num == N) return;
    if(sequence[num] + sum == S) count++;

    DFS(num + 1, sum);
    DFS(num + 1, sum + sequence[num]);
}