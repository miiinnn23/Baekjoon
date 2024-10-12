#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// int board[6][6];
vector<vector<int> > board(5, vector<int>(5));
bool visited[5][5] = { false };

queue<int> relics; // 벽에 적힌 숫자
vector<pair<int, int> > piece;

vector<int> Choice();
int BFS_1(int r, int c, vector<vector<int> > b);
int BFS_2(int r, int c);

vector<vector<int> > Rotate(int r, int c, vector<vector<int> > target);

void Print();

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main(void) {
    int K, M;
    cin >> K >> M;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        int q;
        cin >> q;
        relics.push(q);
    }

    for(int t = 0; t < K; t++) {
        // 1. 유적 탐사
        vector<int> pos = Choice();

        if(pos[0] < 0) continue;

        for(int i = 1; i <= pos[2] / 90; i++)
            board = Rotate(pos[0] - 1, pos[1] - 1, board);

        int sum = 0;
        bool flag = false;

        while(true) {
            int val = 0;

            piece.clear();

            for(int i = 0; i < 5; i++) 
                for(int j = 0; j < 5; j++)
                    visited[i][j] = false;
        
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(!visited[i][j])
                        val += BFS_2(i, j);
                }
            }

            if(val) {
                sort(piece.begin(), piece.end());
                flag = true;
                sum += val;
            }
            
            else break;

            for(int i = 0; i < val; i++) {
                int r = -(piece[i].second);
                int c = piece[i].first;

                board[r][c] = relics.front();
                // relics.push(relics.front());
                relics.pop();
            }
        }
        
        if(!flag) continue;
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}

vector<int> Choice() {
    int current_rot = 360;
    int current_r = 5, current_c = 5;
    int current_val = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 1; k <= 3; k++) {
                vector<int> currentBest = { current_val, -(current_rot), -current_c, -current_r };
                vector<vector<int> > temp_board(5, vector<int>(5));

                for(int y = 0; y < 5; y++)
                    for(int x = 0; x < 5; x++)
                        temp_board[y][x] = board[y][x];

                int val = 0;
                
                for(int t = 1; t <= k; t++) {
                    temp_board = Rotate(i, j, temp_board);
                }
                
                // cout << endl;
                // for(int i = 0; i < 5; i++) {
                //     for(int j = 0; j < 5; j++) {
                //         cout << temp_board[i][j] << " ";
                //     }
                //     cout << endl;
                // }

                for(int y = 0; y < 5; y++) 
                    for(int x = 0; x < 5; x++) 
                        visited[y][x] = false;

                for(int y = 0; y < 5; y++) 
                    for(int x = 0; x < 5; x++)
                        val += BFS_1(y, x, temp_board);    

                if(val == 0) continue;

                vector<int> currentValue = { val, -(k * 90), -(j + 1), -(i + 1) };
                
                if(currentValue > currentBest) {
                    current_val = val;
                    current_rot = k * 90;
                    current_c = j + 1;
                    current_r = i + 1;
                }
            }
        }
    }
    if(current_val == 0) return { -1, -1, -1 };

    vector<int> pos = { current_r, current_c, current_rot };
    return pos;
}

int BFS_1(int r, int c, vector<vector<int> > b) {
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    visited[r][c] = true;
    int val = b[r][c];
    int val_count = 1;

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;

        q.pop();
        for(int i = 0; i < 4; i++) {
            if(nr + dr[i] < 0 || nr + dr[i] >= 5 || nc + dc[i] < 0 || nc + dc[i] >= 5) continue;

            if(!visited[nr + dr[i]][nc + dc[i]] && b[nr + dr[i]][nc + dc[i]] == val) {
                visited[nr + dr[i]][nc + dc[i]] = true;
                q.push(make_pair(nr + dr[i], nc + dc[i]));
                val_count++;
            }
        }
    }
    // 3개 이상 조각들이 연결된 경우만 유물 인정
    return val_count >= 3 ? val_count : 0;
}

int BFS_2(int r, int c) {
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    visited[r][c] = true;
    int val = board[r][c];
    int val_count = 1;
    
    vector<pair<int, int> > temp;
    temp.push_back(make_pair(c, -r));

    while(!q.empty()) {
        int nr = q.front().first;
        int nc = q.front().second;

        q.pop();
        for(int i = 0; i < 4; i++) {
            if(nr + dr[i] < 0 || nr + dr[i] >= 5 || nc + dc[i] < 0 || nc + dc[i] >= 5) continue;

            if(!visited[nr + dr[i]][nc + dc[i]] && board[nr + dr[i]][nc + dc[i]] == val) {
                visited[nr + dr[i]][nc + dc[i]] = true;
                q.push(make_pair(nr + dr[i], nc + dc[i]));
                temp.push_back(make_pair(nc + dc[i], -(nr + dr[i])));
                val_count++;
            }
        }
    }

    if(val_count >= 3) {
        for(int i = 0; i < val_count; i++) piece.push_back(temp[i]);
    }

    // 3개 이상 조각들이 연결된 경우만 유물 인정
    return val_count >= 3 ? val_count : 0;
}

vector<vector<int> > Rotate(int r, int c, vector<vector<int> > target) {
    int temp[5][5] = { 0 };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            temp[i][j] = target[3 - j + r - 1][i + c];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            target[i + r][j + c] = temp[i][j];
        }
    }

    return target;
}


void Print() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}