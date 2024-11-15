#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int N, M;
int map[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
int dist[MAX][MAX] = { 0 };

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

void BFS(int y, int x);

int main(void) {
    int target[] = { 0, 0 };
    
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                target[0] = i;
                target[1] = j;
            }
        }
    }
    
    BFS(target[0], target[1]);
    

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dist[i][j] == 0 && map[i][j] == 1) {
                cout << -1 << " ";
            }
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

void BFS(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visited[y][x] = true;

    while(!q.empty()) {
        int now_y = q.front().first;
        int now_x = q.front().second;
        int d = dist[now_y][now_x];
        q.pop();

        for(int i = 0; i < 4; i++) {
            if(now_y + dy[i] >= N || now_y + dy[i] < 0 || now_x + dx[i] >= M || now_x + dx[i] < 0) continue;
            if(map[now_y + dy[i]][now_x + dx[i]] == 0) continue;

            if(!visited[now_y + dy[i]][now_x + dx[i]]) {
                dist[now_y + dy[i]][now_x + dx[i]] = d + 1;
                visited[now_y + dy[i]][now_x + dx[i]] = true;
                q.push(make_pair(now_y + dy[i], now_x + dx[i]));
            }
        }
    }


}

/*
15 15
2 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 0 1 0 0 0
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
*/