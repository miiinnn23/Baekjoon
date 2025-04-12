#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 65

using namespace std;

int N, Q;

// int board[MAX][MAX] = { 0 };
vector<vector<int> > board;
bool visited[MAX][MAX] = { false };

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void solution();
void rotate(pair<int, int> start, int length);
int BFS(int r, int c);

int main(void) {
    cin >> N >> Q;

    N = (int)pow(2, N);
    board = vector<vector<int> >(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            // board[i][j] = N * i + j + 1;
        }
    }

    solution();

    return 0;
}

void solution() {
    for(int turn = 0; turn < Q; turn++) {
        int L;
        cin >> L;
        
        int len = (int)pow(2, L);

        // 1. 회전
        vector<pair<int, int> > coord;
        for(int i = 0; i < N; i += len) {
            for(int j = 0; j < N; j += len) {
                coord.push_back({i, j});
            }
        }
    
        for(int i = 0; i < coord.size(); i++) {
            rotate(coord[i], len);
        }
        
        // 2. 얼음 계산
        vector<vector<int> > temp = board;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int count = 0;
                if(board[i][j] <= 0) continue; // 얼음 없는 칸 넘어가기

                for(int k = 0; k < 4; k++) {
                    int nr = i + dy[k], nc = j + dx[k];

                    if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    if(board[nr][nc] > 0) count++; // 얼음이 있는 칸 세기
                }

                if(count < 3) temp[i][j] -= 1;
            }
        }

        board.swap(temp);
    }

    // 3. 남아있는 얼음의 합
    int ice = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] <= 0) continue;
            ice += board[i][j];
        }
    }

    // 4. 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
    int max = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && board[i][j] > 0) {
                visited[i][j] = true;
                int iceberg = BFS(i, j);
                max = max < iceberg ? iceberg : max;
            }
        }
    }
    
    cout << ice << "\n" << max;
}

void rotate(pair<int, int> start, int length) {
    vector<vector<int> > temp(length, vector<int>(length, 0));

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            temp[i][j] = board[length - 1 - j + start.first][i + start.second];
        }
    }

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            board[i + start.first][j + start.second] = temp[i][j];
        }
    }
}

int BFS(int r, int c) {
    int sum = 0;

    queue<pair<int, int> > q;
    q.push({r, c});

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        sum++;

        for(int i = 0; i < 4; i++) {
            int nr = cr + dy[i], nc = cc + dx[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            
            if(!visited[nr][nc] && board[nr][nc] > 0) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    return sum;
}