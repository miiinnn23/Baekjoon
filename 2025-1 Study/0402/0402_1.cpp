#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 51

using namespace std;

int N, L, R;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<vector<int> > land;
bool visited[MAX][MAX] = { false };

vector<pair<int, int> > BFS(int r, int c, int id) {
    vector<pair<int, int> > group;
    group.push_back({r, c});

    queue<pair<int, int> > q;
    visited[r][c] = true;

    q.push({r, c});
    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            if(nr + dy[i] < 0 || nr + dy[i] >= N || nc + dx[i] < 0 || nc + dx[i] >= N) continue;
            int diff = abs(land[nr][nc] - land[nr + dy[i]][nc + dx[i]]);
            if(!visited[nr + dy[i]][nc + dx[i]] && diff >= L && diff <= R) {
                q.push({nr + dy[i], nc + dx[i]});
                visited[nr + dy[i]][nc + dx[i]] = true;
                group.push_back({nr + dy[i], nc + dx[i]});
            }
        }
    }

    return group;
}

int main(void) {
    cin >> N >> L >> R;
    
    land.resize(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> land[i][j];
        }
    }
    int day = 0;
    while(true) {
        vector<vector<pair<int, int> > > group;
        memset(visited, false, sizeof(visited));

        int id = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                vector<pair<int, int> > temp;
                if(!visited[i][j]) {
                    temp = BFS(i, j, id++);
                }
                if(temp.size() > 1) group.push_back(temp);
            }
        }
        
        if(group.size() == 0) break;

        for(int i = 0; i < group.size(); i++) {
            int population = 0;
            int country = group[i].size();
            for(int j = 0; j < country; j++) {
                population += land[group[i][j].first][group[i][j].second];
            }
            int moving = population / country;
            for(int j = 0; j < group[i].size(); j++) {
                land[group[i][j].first][group[i][j].second] = moving;
            }
        }

        ++day;
    }
    cout << day << endl;
    return 0;
}