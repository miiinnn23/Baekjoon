#include <cstdio>
#include <queue>
#define MAX 1001

using namespace std;

int tomato[MAX][MAX];
void BFS();
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int m, n;
queue<pair<int, int> > q;

int main(void) {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &tomato[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(tomato[i][j] == 1) {
                q.push(pair<int, int>(i, j));
            }
        }
    }
    BFS();

    int day = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(tomato[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            else {
                day = (day > tomato[i][j] ? day : tomato[i][j]);
            }
        }
    }
    printf("%d\n", day - 1);

    return 0;
}

void BFS() {
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 1 || x + dx[i] > m || y + dy[i] < 1 || y + dy[i] > n) continue;
            if(tomato[y + dy[i]][x + dx[i]] == 0) {
                tomato[y + dy[i]][x + dx[i]] = tomato[y][x] + 1;
                q.push(pair<int, int>(y + dy[i], x + dx[i]));
            }
        }
    }
} 