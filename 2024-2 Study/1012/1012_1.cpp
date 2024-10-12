#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 71

using namespace std;

int R, C, K;
int board[MAX + 3][MAX] = { 0 };
vector<vector<int> > fairy;

int dr[] = { -1, 0, 1, 0 }; // 북 동 남 서
int dc[] = { 0, 1, 0, -1 };  // 0 1 2 3

void Init();
bool Move(int r, int c, int d);
int BFS(int r, int c, int index);

int main(void) {
    cin >> R >> C >> K;
    
    fairy.resize(K, vector<int> (3));

    for(int i = 0; i < K; i++) {
        int c, d;
        fairy[i][0] = 0;
        cin >> fairy[i][1] >> fairy[i][2];
    }
    
    Init();
    int row_sum = 0;

    for(int i = 0; i < K; i++) {
        // 1. 골렘 이동
        while(true) {
            int r = fairy[i][0];
            int c = fairy[i][1];
            
            // cout << r << ", " << c << endl;
            if(Move(r, c, 2)) {
                fairy[i][0] += dr[2];
                fairy[i][1] += dc[2];
            }
            else if(Move(r, c, 3) && Move(r + dr[3], c + dc[3], 2)) {
                fairy[i][0] += dr[3]; fairy[i][1] += dc[3];

                fairy[i][0] += dr[2];
                fairy[i][1] += dc[2];
                fairy[i][2] = (fairy[i][2] + 3) % 4;
                // cout << fairy[i][2] << endl;
            }
            else if(Move(r, c, 1) && Move(r + dr[1], c + dc[1], 2)) {
                fairy[i][0] += dr[1]; fairy[i][1] += dc[1];

                fairy[i][0] += dr[2];
                fairy[i][1] += dc[2];
                fairy[i][2] = (fairy[i][2] + 1) % 4;
                // cout << fairy[i][2] << endl;
            }
            else break;            
        }

        if(fairy[i][0] <= 4) {
            Init();
            continue;
        }

        int r = fairy[i][0], c = fairy[i][1];
        
        board[r][c] = i + 1;
        for(int j = 0; j < 4; j++) {
            if(r + dr[j] < 1 || r + dr[j] > R + 3 || c + dc[j] < 1 || c + dc[j] > C) {
                
                continue;
            }
            board[r + dr[j]][c + dc[j]] = i + 1;
        }

        // cout << endl;
        // for(int k = 3; k <= R + 3; k++) {
        //     for(int l = 1; l <= C; l++) {
        //         cout << board[k][l] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << fairy[i][2] << ", ";
        // 2. BFS연산
        int sum = BFS(r, c, i);
        // cout << sum << endl;
        row_sum += (sum - 3);
    }
    cout << row_sum << endl;
    return 0;
}

int BFS(int r, int c, int index) {
    queue<pair<int, int> > q;
    
    vector<pair<int, int> > pos;
    bool visited[MAX + 3][MAX] = { false };
    visited[r][c] = true;

    q.push(make_pair(r, c));
    pos.push_back(make_pair(r, c));

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;
        int now = board[nr][nc];

        q.pop();

        for(int i = 0; i < 4; i++) {
            if(nr + dr[i] < 1 || nr + dr[i] > R + 3 || nc + dc[i] < 1 || nc + dc[i] > C) continue;
            if(i == fairy[now - 1][2]) { // 현재 위치가 탈출구인 경우 인접한 골렘으로 이동 가능
                if(!visited[nr + dr[i]][nc + dc[i]] && board[nr + dr[i]][nc + dc[i]] != 0) {
                    visited[nr + dr[i]][nc + dc[i]] = true;
                    q.push(make_pair(nr + dr[i], nc + dc[i]));
                    pos.push_back(make_pair(nr + dr[i], nc + dc[i]));
                }
            }
            else {
                if(!visited[nr + dr[i]][nc + dc[i]] && board[nr + dr[i]][nc + dc[i]] == now) {
                    visited[nr + dr[i]][nc + dc[i]] = true;
                    q.push(make_pair(nr + dr[i], nc + dc[i]));
                    pos.push_back(make_pair(nr + dr[i], nc + dc[i]));
                }
            }
        }
    }

    sort(pos.begin(), pos.end());
    int size = pos.size();
    
    return pos[size - 1].first;
}

bool Move(int r, int c, int d) {
    // 초록색 칸으로 이동했을 경우 예상 중심 위치
    int nr = r + dr[d];
    int nc = c + dc[d];

    for(int i = 0; i < 4; i++) {
        if(nr == 0 && i == 0) continue;
        if(i == (d + 2) % 4) continue; // 이동방향의 반대 위치는 확인할 필요 없음

        if(nr + dr[i] > R + 3 || nc + dc[i] < 1 || nc + dc[i] > C) return false; // 칸을 벗어나는 경우 제외
        if(board[nr + dr[i]][nc + dc[i]] != 0) return false; // 초록색 칸이 하나라도 비어있지 않으면 이동 불가
    }
    return true;
}

void Init() { // 보드판 초기화
    for(int i = 0; i <= R + 3; i++)
        for(int j = 0; j <= C; j++) // 씨발아....ㅜㅜ
            board[i][j] = 0;
}