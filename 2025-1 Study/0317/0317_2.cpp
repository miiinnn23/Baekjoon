#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

bool visited[MAX][MAX] = { false };
int graph[MAX][MAX] = { 0 };
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int BFS(int start_r, int start_c, int group_id, vector<vector<int> > land) {
    queue<pair<int, int> > q;
    int r = land.size();
    int c = land[0].size();
    
    int group_cnt = 1;
    visited[start_r][start_c] = true;

    q.push(make_pair(start_r, start_c));

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        graph[nr][nc] = group_id;
        
        q.pop();

        for(int i = 0; i < 4; i++) {
            if(nr + dy[i] < 0 || nr + dy[i] >= r || nc + dx[i] < 0 || nc + dx[i] >= c) continue;
            if(!visited[nr + dy[i]][nc + dx[i]] && land[nr + dy[i]][nc + dx[i]] == 1) {
                visited[nr + dy[i]][nc + dx[i]] = true;
                q.push(make_pair(nr + dy[i], nc + dx[i]));
                group_cnt++;
            }
        }
    }
    
    return group_cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int r = land.size();
    int c = land[0].size();
    vector<int> group(r * c + 1, 0);
    
    int group_id = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(land[i][j] == 1 && !visited[i][j]) {
                group_id++;
                group[group_id] = BFS(i, j, group_id, land);
            }
        }
    }

    int max = 0;
    for(int j = 0; j < c; j++) {
        int count = 0;
        vector<bool> group_visited(group_id + 1, false);

        for(int i = 0; i < r; i++) {
            int gid = graph[i][j];
            if(gid != 0 && !group_visited[gid]) {
                count += group[gid];
                group_visited[gid] = true;
            }
        }

        max = max < count ? count : max;
    }

    return max;
}


int main(void) {
    int r, c;
    cin >> r >> c;
    vector<vector<int > > land(r, vector<int>(c));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> land[i][j];
        }
    }

    cout << solution(land) << endl;
    return 0;
}

/*

5 8
0 0 0 1 1 1 0 0  
0 0 0 0 1 1 0 0 
1 1 0 0 0 1 1 0
1 1 1 0 0 0 0 0
1 1 1 0 0 0 1 1

7 6
1 0 1 0 1 1
1 0 1 0 0 0
1 0 1 0 0 1
1 0 0 1 0 0
1 0 0 1 0 1
1 0 0 0 0 0
1 1 1 1 1 1


*/