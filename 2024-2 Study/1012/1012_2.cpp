#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 21

using namespace std;

int T, N;

int startX, startY;
int max_len;
int board[MAX][MAX];
vector<int> temp;

void DFS(int r, int c, int dir);
void Init();

int dy[] = { 1, 1, -1, -1 };
int dx[] = { 1, -1, -1, 1 };

int main(void) {
    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> N;

        max_len = -1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                temp.clear();
                startY = i, startX = j;
                temp.push_back(board[startY][startX]);
                
                DFS(i, j, 0);
            }
        }
        cout << '#' << t << " " << max_len << endl;
    }
 
    return 0;
}

void DFS(int r, int c, int dir) {
    int nr = r + dy[dir];
    int nc = c + dx[dir];

    if(dir == 3 && nr == startY && nc == startX) { // 처음으로 다시 돌아왔을 때
        int size = temp.size();
        if(max_len < size) {
            max_len = size;
            return;
        }
    }

    if(nr < 0 || nr >= N || nc < 0 || nc >= N) return;
    if(find(temp.begin(), temp.end(), board[nr][nc]) != temp.end()) return;
    // find함수는 찾을 경우 iterator를, 못찾으면 end를 return
    // 못찾았을 경우가 아니면 탐색 종료
    temp.push_back(board[nr][nc]);
    // cout << temp.size() << endl;
    if(dir == 3)
        DFS(nr, nc, dir);

    else {
        DFS(nr, nc, dir); // 가던 방향으로 계속 가기
        DFS(nr, nc, dir + 1); // 가던 방향에서 꺾기
    }
    temp.pop_back();
    return;
}