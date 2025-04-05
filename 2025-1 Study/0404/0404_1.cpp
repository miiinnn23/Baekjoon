#include <iostream>
#define MAX 51

using namespace std;
int R, C, T;

int board[MAX][MAX];
int copy_board[MAX][MAX];

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
int air_purifier[2] = { 0 };

void cleaning();

int solution() {
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                copy_board[i][j] = board[i][j];


        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(board[i][j] > 0) {
                    int count = 0;
                    int dust = board[i][j] / 5;
                    for(int k = 0; k < 4; k++) {
                        int nr = i + dy[k] , nc = j + dx[k];
                        if(nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] == -1) continue;

                        copy_board[nr][nc] += dust;
                        count++;
                    }
                    copy_board[i][j] -= dust * count;
                }
                else continue;
            }
        }
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                board[i][j] = copy_board[i][j];

        // 청소
        cleaning();
    }

    int sum = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] > 0) sum += board[i][j];
        }
    }

    return sum;
}

int main(void) {
    cin >> R >> C >> T;

    int air = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            if(board[i][j] == -1) air_purifier[air++] = i;
        }
    }

    cout << solution() << endl;

    return 0;
}

void cleaning() {
    // upside
    for(int r = air_purifier[0] - 1; r >= 1; r--) {
        board[r][0] = board[r - 1][0];
    }
    for(int c = 0; c < C - 1; c++) {
        board[0][c] = board[0][c + 1];
    }
    for(int r = 0; r < air_purifier[0]; r++) {
        board[r][C - 1] = board[r + 1][C - 1];
    }
    for(int c = C - 1; c >= 1; c--) {
        board[air_purifier[0]][c] = board[air_purifier[0]][c - 1];
        if(board[air_purifier[0]][c] == -1) board[air_purifier[0]][c] = 0;
    }

    // downside
    for(int r = air_purifier[1] + 1; r < R - 1; r++) {
        board[r][0] = board[r + 1][0];
    }
    for(int c = 0; c < C - 1; c++) {
        board[R - 1][c] = board[R - 1][c + 1];
    }
    for(int r = R - 1; r > air_purifier[1]; r--) {
        board[r][C - 1] = board[r - 1][C - 1];
    }
    for(int c = C - 1; c >= 1; c--) {
        board[air_purifier[1]][c] = board[air_purifier[1]][c - 1];
        if(board[air_purifier[1]][c] == -1) board[air_purifier[1]][c] = 0;
    }
}