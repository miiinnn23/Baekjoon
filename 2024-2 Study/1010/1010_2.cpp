#include <iostream>
#define MAX 52
#define SANTA_MAX 32

using namespace std;

int N, M, P, C, D;
int point[SANTA_MAX];
pair<int, int> Santa[MAX]; // 산타의 좌표
pair<int, int> Rudolph; // 루돌프의 좌표

int board[MAX][MAX] = { 0 };
bool IsAlive[SANTA_MAX];
int stun[SANTA_MAX];

int dc[] = { 0, 1, 0, -1 }; // 우선순위 - 상우하좌
int dr[] = { -1, 0, 1, 0 };

int Distance(int x1, int x2, int y1, int y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }
bool InRange(int r, int c) { return r > 0 && r <= N && c > 0 && c <= N; }

void Game(int turn);
void Rudolph_move(int turn);
void Santa_move(int turn);

void Print() {
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    cin >> N >> M >> P >> C >> D;

    cin >> Rudolph.first >> Rudolph.second;
    board[Rudolph.first][Rudolph.second] = -1;

    for(int i = 1; i <= P; i++) {
        int n, r, c;
        cin >> n >> r >> c;
        Santa[n].first = r;
        Santa[n].second = c;
        
        board[r][c] = n;
        IsAlive[n] = true;
    }

    Print();
    
    for(int t = 0; t < M; t++) {
        // Game(t);
    }

    for(int i = 1; i <= P; i++) {
        cout << point[i] << " ";
    }
    cout << endl;
    return 0;
}

void Game(int turn) {
    Rudolph_move(turn);
    Santa_move(turn);
}

void Rudolph_move(int turn) {
    int min_r = MAX + 1, min_c = MAX + 1, min_index = -1;

    for(int i = 1; i <= P; i++) {
        if(!IsAlive[i]) continue;
        // 비교방법 좋다..
        pair<int, pair<int, int> > currentBest = { Distance(min_r, Rudolph.first, min_c, Rudolph.second), {-min_r, -min_c}};
        pair<int, pair<int, int> > currentValue = { Distance(Santa[i].first, Rudolph.first, Santa[i].second, Rudolph.second), {-Santa[i].first, -Santa[i].second}};


        if(currentBest > currentValue) { // int -> pair<int, int> 순으로 비교
            min_r = Santa[i].first;
            min_c = Santa[i].second;
            min_index = i;
        }
    }
    
    cout << min_index << endl;
    if(min_index) { // min_index가 존재할 경우
        pair<int, int> prev = Rudolph;
        // 가장 가까운 산타와 가까워지는 방향으로 한칸 이동
        // r, c 좌표가 둘 다 차이날 경우 대각선 방향 이동 우선
        // 이후 r 또는 c가 같아진 경우 상하좌우 이동
        int moveR = 0;
        if(Rudolph.first < min_r) moveR = 1;
        else if(Rudolph.first > min_r) moveR = -1;

        int moveC = 0;
        if(Rudolph.second < min_c) moveC = 1;
        else if(Rudolph.second > min_c) moveC = -1;

        Rudolph.first += moveR;
        Rudolph.second += moveC;
        board[prev.first][prev.second] = 0;

        if(Rudolph.first == min_r && Rudolph.second == min_c) { // 루돌프의 이동으로 산타와 충돌한 경우
            int firstR = min_r + moveR * C;
            int firstC = min_c + moveC * C;
            int lastR = firstR;
            int lastC = firstC;

            stun[min_index] = turn + 1; // 충돌 발생으로 turn + 1 까지 기절
            
            // 이동한 위치에 산타가 있을 경우 연쇄적으로 한칸씩 밀려남, 마지막 도착위치 연산
            while(InRange(lastR, lastC) && board[lastR][lastC] > 0) {
                lastR += moveR;
                lastC += moveC;
            }

            // 연쇄적으로 충돌이 일어난 가장 마지막 위치에서 시작해서 순차적으로 보드판에 있는 산타 한칸씩 이동
            while(!(lastR == firstR && lastC == firstC)) {
                int beforeR = lastR - moveR;
                int beforeC = lastC - moveC;

                if(!InRange(beforeR, beforeC)) break; // 벗어날 경우 탈락

                int index = board[beforeR][beforeC];

                if(!InRange(lastR, lastC)) IsAlive[index] = false;
                else {
                    board[lastR][lastC] = board[beforeR][beforeC];
                    Santa[index] = { lastR, lastC };
                }

                lastR = beforeR;
                lastC = beforeC;
            }

            point[min_index] += C;
            Santa[min_index] = { firstR, firstC };
            if(InRange(firstR, firstC)) board[firstR][firstC] = min_index;
            else IsAlive[min_index] = false;
        }
    }

    board[Rudolph.first][Rudolph.second] = -1;

}

void Santa_move(int turn) {
    for(int i = 1; i <= P; i++) {
        // 살아있지 않거나 기절한 경우
        if(!IsAlive[i] || stun[i] >= turn) continue;

        int minDist = Distance(Santa[i].first, Rudolph.first, Santa[i].second, Rudolph.second);
        int moveDir = -1;

        for(int dir = 0; dir < 4; dir++) {
            int nr = Santa[i].first + dr[dir];
            int nc = Santa[i].second + dc[dir];

            if(!InRange(nr, nc) || board[nr][nc] > 0) continue;

            int dist = Distance(nr, Rudolph.first, nc, Rudolph.second);
            if(minDist > dist) {
                minDist = dist;
                moveDir = dir;
            }
        }

        if(moveDir != -1) {
            int nr = Santa[i].first + dr[moveDir];
            int nc = Santa[i].second + dc[moveDir];

            if(nr == Rudolph.first && nc == Rudolph.second) { // 산타 '끼리' 충돌 발생
                stun[i] = turn + 1;

                int moveR = -dr[moveDir];
                int moveC = -dc[moveDir];

                int firstR = nr + moveR * D;
                int firstC = nc + moveC * D;
                int lastR = firstR;
                int lastC = firstC;

                if(D == 1) point[i] += D;
                else {
                    while(InRange(lastR, lastC) && board[lastR][lastC] > 0) {
                        lastR += moveR;
                        lastC += moveC;
                    }

                    while(!(lastR == firstR && lastC == firstC)) {
                        int beforeR = lastR - moveR;
                        int beforeC = lastC - moveC;

                        if(!InRange(beforeR, beforeC)) break;

                        int index = board[beforeR][beforeC];

                        if(!InRange(lastR, lastC)) IsAlive[index] = false;
                        else {
                            board[lastR][lastC] = board[beforeR][beforeC];
                            Santa[index] = { lastR, lastC };
                        }

                        lastR = beforeR;
                        lastC = beforeC;
                    }

                    point[i] += D;
                    board[Santa[i].first][Santa[i].second] = 0;
                    Santa[i] = { firstR, firstC };
                    if(InRange(firstR, firstC)) board[firstR][firstC] = i;
                    else IsAlive[i] = false;
                }   
            }
            else {
                board[Santa[i].first][Santa[i].second] = 0;
                Santa[i] = { nr, nc };
                board[nr][nc] = i;
            }
        }
    }

    for(int i = 1; i <= P; i++) {
        if(IsAlive[i]) point[i]++;
    }
}