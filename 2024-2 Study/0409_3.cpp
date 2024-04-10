#include <iostream>
#include <vector>
#include <cstring>

#include <queue>

#define MAX 101

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int visited[MAX][MAX] = { 0 };
queue<pair<int, int> > board;

void BFS(vector<vector<int> > maps) {
    int x = maps[0].size();
    int y = maps.size();
    
    visited[0][0] = 1;
    
    while(!board.empty()) {
        int b = board.front().first;
        int a = board.front().second;
        
        board.pop();
        for(int i = 0; i < 4; i++) {
            if(a + dx[i] < 0 || a + dx[i] >= x || b + dy[i] < 0 || b + dy[i] >= y) continue;

            if(visited[b + dy[i]][a + dx[i]] == 0 && maps[b + dy[i]][a + dx[i]] == 1) {
                visited[b + dy[i]][a + dx[i]] = visited[b][a] + 1;
                board.push(make_pair(b + dy[i], a + dx[i]));
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    int x = maps[0].size();
    int y = maps.size();

    board.push(make_pair(0, 0));
    BFS(maps);
    
    if(visited[y - 1][x - 1] == 0) return -1;
    return visited[y - 1][x - 1];
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int > > maps;
    for(int i = 0; i < M; i++) {
        vector<int> temp;
        for(int j = 0; j < N; j++) {
            int tempNum;
            cin >> tempNum;
            temp.push_back(tempNum);
        }
        maps.push_back(temp);
    }

    cout << solution(maps) << endl;

    return 0;
}