#include <cstdio>
#include <queue>
#include <climits>
#include <cstring>
#define MAX 101

using namespace std;

int n;
bool visited[MAX][MAX];
int island[MAX][MAX];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int BFS(int c);
void DFS(int a, int b, int c);

int main(void) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &island[i][j]);
        }
    }

    int c = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(island[i][j] == 1 && !visited[i][j]) {
                DFS(i, j, c);
                c++;
            }
        }
    }

    int result = INT_MAX;
    for(int i = 1; i < c; i++) {
        memset(visited, false, sizeof(visited)); // 매번 초기화 필수!!!
        int temp = BFS(i);
        result = (result < temp ? result : temp);
    }

    printf("%d\n", result);
    return 0;
}

int BFS(int c) {
    queue<pair<int, int> > q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= n; j++) {
            if(island[i][j] == c) {
                visited[i][j] = true;
                q.push(pair<int, int>(i, j));
            }
        }
    }

    int distance = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int k = 0; k < size; k++) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++) {
                if(y + dy[i] < 1 || y + dy[i] > n || x + dx[i] < 1 || x + dx[i] > n) continue;
                
                if(island[y + dy[i]][x + dx[i]] && island[y + dy[i]][x + dx[i]] != c)
                    return distance;    // 목적지 도달
                else if(!island[y + dy[i]][x + dx[i]] && !visited[y + dy[i]][x + dx[i]]) {
                    visited[y + dy[i]][x + dx[i]] = true;
                    q.push(pair<int, int>(y + dy[i], x + dx[i]));
                }
            }
        }
        distance++;
    }
    return 0;
}

void DFS(int a, int b, int c) {
    visited[a][b] = true;
    island[a][b] = c;

    for(int i = 0; i < 4; i++) {
        if(a + dy[i] < 1 || a + dy[i] > n || b + dx[i] < 1 || b + dx[i] > n) continue;

        if(island[a + dy[i]][b + dx[i]] == 1 && !visited[a + dy[i]][b + dx[i]])
            DFS(a + dy[i], b + dx[i], c);
    }
}