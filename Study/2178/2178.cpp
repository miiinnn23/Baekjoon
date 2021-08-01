#include <cstdio>
#include <queue>
#define MAX 101

using namespace std;

int maze[MAX][MAX];
int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS();
int count;
queue<pair<int, int> > q;

int main(void) {    
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    BFS();

    printf("%d\n", maze[n][m]);
    return 0;
}

void BFS() {
    q.push(pair<int, int>(1, 1));
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 1 || x + dx[i] > m || y + dy[i] < 1 || y + dy[i] > n) continue;
            if(maze[y + dy[i]][x + dx[i]] == 1) {
                maze[y + dy[i]][x + dx[i]] = maze[y][x] + 1;
                q.push(pair<int, int>(y + dy[i], x + dx[i]));
            }
        }
    }
}