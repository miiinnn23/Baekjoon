#include <cstdio>
#define MAX 101
#define INF 10000001

using namespace std;

int route[MAX][MAX];
int N, K;

int main(void) {
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            route[i][j] = INF;
        }
    }

    for(int i = 0; i < K; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(route[a][b] > c) {
            route[a][b] = c;
        }
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(route[i][k] + route[k][j] < route[i][j]) {
                    route[i][j] = route[i][k] + route[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j || route[i][j] >= INF) printf("0 ");
            else printf("%d ", route[i][j]);
        }
        printf("\n");
    }
    return 0;
}