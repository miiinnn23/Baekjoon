#include <cstdio>
#define MAX 2002

bool result[MAX];
int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        result[num + 1000] = true;
    }

    for(int i = 0; i < MAX; i++) {
        if(result[i]) {
            printf("%d ", i - 1000);
        }
    }
    printf("\n");
    return 0;
}