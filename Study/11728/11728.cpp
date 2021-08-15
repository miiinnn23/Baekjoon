#include <cstdio>
#define MAX 1000001

int N, M;
int A[MAX];
int B[MAX];
int Result[MAX + MAX];

void merge();

int main(void) {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }

    merge();
    
    for(int i = 0; i < (N + M); i++) {
        printf("%d ", Result[i]);
    }
    printf("\n");
    return 0;
}

void merge() {
    int i = 0, j = 0, k = 0;
    while(i < N && j < M) {
        if(A[i] <= B[j]) {
            Result[k] = A[i];
            i++;
        }
        else {
            Result[k] = B[j];
            j++;
        }
        k++;
    }
    if(i >= N) {
            for(int t = j; t < M; t++, k++) {
                Result[k] = B[t];
            }
        }
    else {
        for(int t = i; t < N; t++, k++) {
            Result[k] = A[t];
        }
    }
}