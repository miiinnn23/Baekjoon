#include <iostream>
#include <vector>
#define MAX 12

using namespace std;

int maze[MAX][MAX] = { 0 };
int n, m;
int exit_loc[] = { 0, 0 };
int moving = 0;
int move_count = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

vector<vector<int> > participant;

int Distance(int x1, int y1, int x2, int y2) {
    int x = (x1 - x2) > 0 ? x1 - x2 : x2 - x1;
    int y = (y1 - y2) > 0 ? y1 - y2 : y2 - y1;
    return x + y;
}

int max(int x, int y) { return x > y ? x : y; }
int max_dist(int x, int y) {
    // 그냥 귀찮으니까.. 여기서 변환
    x = x >= 0 ? x : -x;
    y = y >= 0 ? y : -y;

    return max(x, y);
}

bool IsWall(int r, int c) { return maze[r][c] > 0; }

void Move();
void Rotation(int square, int r, int c);


void Print();

int main(void) {
    int k;
    cin >> n >> m >> k;

    participant.resize(m, vector<int>(3));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> maze[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> participant[i][0] >> participant[i][1];
        participant[i][2] = 0;
    }

    cin >> exit_loc[0] >> exit_loc[1];

    Print();
    for(int t = 0; t < k; t++) {
        Move();
        Print();
        
        if(m == 0) break;
    }

    // cout << moving << endl;
    cout << move_count << endl;
    cout << exit_loc[0] << " " << exit_loc[1] << endl;
    return 0;
}

void Move() {
    // 1. 참가자 이동
    vector<int> escape;
    for(int i = 0; i < m; i++) {
        int r = participant[i][0];
        int c = participant[i][1];

        for(int j = 0; j < 4; j++) {
            if(r + dy[j] < 1 || r + dy[j] > n || c + dx[j] < 1 || c + dx[j] > n) continue; // 이동 방향이 칸을 넘어가는 경우
            if(IsWall(r + dy[j], c + dx[j])) continue; // 이동 방향에 벽이 있는 경우

            // 이동하려는 위치가 기존 위치 대비 출구와 최단거리가 더 가까울 때만 이동
            if(Distance(r, c, exit_loc[0], exit_loc[1]) > Distance(r + dy[j], c + dx[j], exit_loc[0], exit_loc[1])) {
                r = r + dy[j];
                c = c + dx[j];
                move_count++;
                break;
            }
        }

        participant[i][0] = r;
        participant[i][1] = c;
        participant[i][2]++;

        if(participant[i][0] == exit_loc[0] && participant[i][1] == exit_loc[1]) {
            moving += participant[i][2];
            escape.push_back(i);
        }
    }

    Print();
    // 출구에 도다른 인원 탈출
    int e = escape.size();
    if(e > 0) {
        for(int i = e - 1; i >= 0; i--) {
            participant.erase(participant.begin() + escape[i]);
            m--;
        }
    }

    if(m == 0) return;
    // 2. 정사각형 회전
    int square = n + 1;
    int start_r = n, start_c = n;

    for(int i = 0; i < m; i++) {
        int dist = max_dist(participant[i][0] - exit_loc[0], participant[i][1] - exit_loc[1]) + 1;
        if(dist <= square) square = dist;  // 최소 한명 이상의 참가자와 출구를 포함한 정사각형의 최단거리 찾기
    }

    for(int i = 0; i < m; i++) {
        int dist = max_dist(participant[i][0] - exit_loc[0], participant[i][1] - exit_loc[1]) + 1;
        if(dist == square) {
            int r = max(max(participant[i][0], exit_loc[0]) - dist + 1, 1);
            int c = max(max(participant[i][1], exit_loc[1]) - dist + 1, 1);

            if(r <= start_r) {
                if(r < start_r) {
                    start_r = r;
                    start_c = c;
                }
                if(r == start_r && c <= start_c) {
                    start_r = r;
                    start_c = c;
                }
            }
        }
    }

    Rotation(square, start_r, start_c);
    
    for(int i = 0; i < m; i++) {
        if(participant[i][0] >= start_r && participant[i][0] < start_r + square && participant[i][1] >= start_c && participant[i][1] < start_c + square) {
            int dr = participant[i][0] - start_r;
            int dc = participant[i][1] - start_c;

            participant[i][0] = start_r + dc;
            participant[i][1] = start_c + square - dr - 1;

            // int r = start_r + start_c - participant[i][1];
            // int r = participant[i][1];
            // int c = start_r + square - participant[i][0];

            // participant[i][0] = r;
            // participant[i][1] = c;
        }
    }

    // int er = exit_loc[0], ec = exit_loc[1];
    int dr = exit_loc[0] - start_r, dc = exit_loc[1] - start_c;
    // cout << exit_loc[0] << exit_loc[1] << endl;
    // exit_loc[0] = start_r + start_c - ec;
    exit_loc[0] = start_r + dc;
    exit_loc[1] = start_c + square - dr - 1; 
}

void Rotation(int square, int r, int c) {
    int** temp = new int* [square];
    for(int i = 0; i < square; i++) {
        temp[i] = new int[square];
    }

    for(int i = 0; i < square; i++) {
        for(int j = 0; j < square; j++) {
            // 회전 시 내구도 1 감소
            temp[i][j] = IsWall(r + square - j - 1, c + i) ? maze[r + square - j - 1][c + i] - 1 : 0;
        }
    }

    for(int i = 0; i < square; i++) {
        for(int j = 0; j < square; j++) {
            maze[i + r][j + c] = temp[i][j];
        }
    }
}

void Print() {

    cout << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c = '0';
            if(IsWall(i, j)) c = '0' + maze[i][j];

            for(int k = 0; k < m; k++) {
                if(participant[k][0] == i && participant[k][1] == j) c = 'A' + k;
            }
            
            if(exit_loc[0] == i && exit_loc[1] == j) c = 'X';
            cout << c << " ";
        }
        cout << endl;
    }
}