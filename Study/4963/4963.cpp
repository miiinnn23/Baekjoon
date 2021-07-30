#include <cstdio>
#define MAX 51

int w, h;
int island[MAX][MAX];
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = { 0, 1, 0, -1, 1, -1, -1, 1};

void DFS(int a, int b);

int main(void) {
    while(true) {
        int c = 0;
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;

        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                scanf("%d", &island[i][j]);
            }
        }

        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                if(island[i][j] == 1) {
                    DFS(i, j);
                    c++;
                }
            }
        }

        printf("%d\n", c);
    }
    return 0;
}

void DFS(int a, int b) {
    island[a][b] = 0;

    for(int i = 0; i < 8; i++) {
        if((a + dy[i] < 1) || (a + dy[i] > h) || (b + dx[i] < 1) || (b + dx[i] > w))
            continue;
            
        if(island[a + dy[i]][b + dx[i]] == 1)
            DFS(a + dy[i], b + dx[i]);
    }
}