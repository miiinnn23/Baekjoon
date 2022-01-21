#include <cstdio>
#define MAX 21

int city[MAX][MAX];
bool noroute[MAX][MAX];

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &city[i][j]);
        }
    }
    
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(city[i][j] > city[i][k] + city[k][j]) {
                    printf("-1\n");
                    return 0;
                }
                if(i != k && j != k && city[i][k] + city[k][j] == city[i][j]) 
                    noroute[i][j] = true;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!noroute[i][j]) count += city[i][j];
        }
    }

    printf("%d\n", count / 2);
    return 0;
}