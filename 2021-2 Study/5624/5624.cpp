#include <cstdio>
#define MAX 5000

int A[MAX];
bool visited[400001] = { false };

int DP(int num);

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("%d\n", DP(N));
    return 0;
}

int DP(int num) {
    int result = 0;

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < i; j++) {
            if(visited[A[i] - A[j] + 200000]) {
                result++;
                break;
            }
        }

        for(int j = 0; j <= i; j++) {
            visited[A[i] + A[j] + 200000] = true;
        }
    }
    return result;
}