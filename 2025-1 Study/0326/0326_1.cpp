#include <iostream>
#include <vector>
#define MAX 21

using namespace std;
int board[MAX][MAX];
int N, M;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void solution(int K, int r, int c);

int main(void) {
    int x, y, K;
    cin >> N >> M >> x >> y >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solution(K, x, y);
    return 0;
}

void solution(int K, int r, int c) {
    int dice[7] = { 0 };
    int top = 1, front = 5, east = 3;

    for(int com = 0; com < K; com++) {
        int dir;
        cin >> dir;
        
        if(r + dy[dir - 1] < 0 || r + dy[dir - 1] >= N || c + dx[dir - 1] < 0 || c + dx[dir - 1] >= M) continue;
        
        r += dy[dir - 1];
        c += dx[dir - 1];
        
        int new_top;
        if(dir == 1) {
            new_top = 7 - east;
            east = top;
        }
        else if(dir == 2) {
            new_top = east;
            east = 7 - top;
        }
        else if(dir == 3) {
            new_top = front;
            front = 7 - top;
        }
        else {
            new_top = 7 - front;
            front = top;
        }
        top = new_top;

        cout << dice[top] << endl;
        if(board[r][c] != 0) {
            dice[7 - top] = board[r][c];
            board[r][c] = 0;
        }
        else {
            board[r][c] = dice[7 - top];
        }
            
    }
}