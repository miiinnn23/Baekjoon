#include <iostream>
#include <vector>
#include <queue>
#define MAX 42

using namespace std;

// 다시생각해볼것

int L, N, Q;
int board[MAX][MAX];

typedef struct Knight {
    int r, c, h, w, k;
    // (r, c) : 시작 좌표
    // h : 세로
    // w : 가로
    // k : 초기 체력
} Knight;

vector<Knight> player;


bool IsDead(Knight P) { return P.k <= 0; } // 체력 이상의 데미지를 받았을 경우 죽음
int nr[MAX], nc[MAX];
bool flag[MAX] = { false };
int damage[MAX];
int before[MAX];

// int damage = 0; // 전체 데미지

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool Move(int num, int d);

int main() {
    cin >> L >> N >> Q;

    // 초기 입력(체스판, 기사, 명령)
    for(int i = 1; i <= L; i++) {
        for(int j = 1; j <= L; j++) {
            cin >> board[i][j];
        }
    }
    
    // 기사 번호는 1번부터 시작, 시작 index 0번에 의미없는 기사 추가
    Knight none = { 0, 0, 0, 0, 0 };
    player.push_back(none);

    for(int i = 1; i <= N; i++) {
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        Knight P = {r, c, h, w, k};
        before[i] = k;
        player.push_back(P);
    }

    for(int t = 0; t < Q; t++) {
        int i, d;
        cin >> i >> d;
        if(IsDead(player[i])) continue; // 체스판에서 사라진 기사에게 명령을 내리면 아무 반응이 없음
        else {
            if(Move(i, d)) {
                for(int i = 1; i <= N; i++) {
                    player[i].r = nr[i];
                    player[i].c = nc[i];
                    player[i].k -= damage[i];
                }
            }
        }
    }

    cout << player[3].r << ", " << player[3].c << endl;

    long long sum = 0;
    for(int i = 1; i <= N; i++) {
        if(IsDead(player[i])) continue;
        // cout << i << " " << before[i] << " " << player[i].k << endl;
        sum += before[i] - player[i].k;
    }

    cout << sum << endl;
    return 0;
}

bool Move(int num, int d) {
    for(int i = 1; i <= L; i++) {
        flag[i] = false;
        nr[i] = player[i].r;
        nc[i] = player[i].c;
        damage[i] = 0;
    }

    queue<int> q;
    q.push(num);
    flag[num] = true;

    while(!q.empty()) {
        int next = q.front();
        q.pop();

        nr[next] += dy[d];
        nc[next] += dx[d];

        if(nr[next] < 1 || nr[next] + player[next].h - 1 > L || nc[next] < 1 || nc[next] + player[next].w - 1 > L) {
            return false; // 기사가 이동하려는 방향의 끝에 벽이 있다면 모든 기사는 이동할 수 없음
        }

        for(int i = nr[next]; i <= nr[next] + player[next].h - 1; i++) {
            for(int j = nc[next]; j <= nc[next] + player[next].w - 1; j++) {
                if(board[i][j] == 2) return false;
                if(board[i][j] == 1) {
                    damage[next]++;
                }
            }
        }

        for(int i = 1; i <= N; i++) {
            if(flag[i] || IsDead(player[i])) continue;
            if(player[i].r > nr[next] + player[next].h - 1 || nr[next] > player[i].r + player[i].h - 1) continue;
            if(player[i].c > nc[next] + player[next].w - 1 || nc[next] > player[i].c + player[i].w - 1) continue;

            flag[i] = true;
            q.push(i);
        }
    }
    
    damage[num] = 0;
    return true;
}