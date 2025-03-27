#include <iostream>
#include <queue>
#include <vector>
#define MAX 8

using namespace std;

int N, M, answer = -1;
// vector<vector<int> > map;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int BFS(const vector<vector<int> >& map) {
    int count = 0;

    queue<pair<int, int> > q;
    vector<vector<int>> copy(map);

    bool visited[MAX][MAX] = { false };

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(copy[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_r = nr + dy[i];
            int next_c = nc + dx[i];
            
            if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
            
            if(!visited[next_r][next_c] && copy[next_r][next_c] == 0) {
                copy[next_r][next_c] = 2;
                visited[next_r][next_c] = true;
                q.push({next_r, next_c});
            }
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(copy[i][j] == 0) count++;


    return count;
}

void DFS(int r, int c, int count, vector<vector<int> >& map) {
    if(count == 3) {
        int num = BFS(map);
        answer = answer < num ? num : answer;
        return;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                DFS(i, j, count + 1, map);
                map[i][j] = 0;
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
     
    vector<vector<int > > map(N, vector<int>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                DFS(i, j, 1, map);
                map[i][j] = 0;
            }
        }
    }

    cout << answer << endl;
    return 0;
}