#include <iostream>
#include <vector>
#define MAX 500
#define MOD 100

using namespace std;

int board[MAX][MAX] = { 0 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N;

vector<vector<vector<int>>> window;

vector<vector<int>> Window_Rotate(const vector<vector<int>>& w) {
    vector<vector<int> > new_window(5, vector<int>(5, 0));
    
    for(int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            new_window[i][j] = w[j][4 - i];

    return new_window;
}

vector<vector<int>> Window_Calc(const vector<vector<int>> &w, int y) {
    vector<vector<int>> new_window(5, vector<int>(5, 0));

    int alpha_r = 0, alpha_c = 0;
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(w[i][j] < 0) { alpha_r = i, alpha_c = j; } // alpha 자리 처리
            else {
                new_window[i][j] = (w[i][j] * y) / MOD;
                sum += new_window[i][j];
            }
        }
    }
    new_window[alpha_r][alpha_c] = y - sum;

    return new_window;
}

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    int answer = 0;

    int start = N / 2;
    int r = start, c = start;
    int dir = 0;

    int count = 2, move_count = 1, dist = 1, dist_count = 0;

    window.push_back({{0, 0, 2, 0, 0}, {0, 10, 7, 1, 0}, {5, -1, 0, 0, 0}, {0, 10, 7, 1, 0}, {0, 0, 2, 0, 0}});
    for(int i = 1; i < 4; i++) {
        vector<vector<int> > before = window[i - 1];
        before = Window_Rotate(before);
        window.push_back(before);
    }

    for(int t = 0; t < N * N - 1; t++) {
        // 현재 위치: x의 좌표
        
        // 토네이도 이동
        if(dist_count == dist) {
            if(move_count == count) {
                dist++;
                
                if(dist != N - 1) count = 2;
                else count = 3;
                
                dist_count = 0;
                move_count = 1;
            }
            else {
                dist_count = 0;
                move_count++;
            }
            // window 회전
            dir = (dir + 1) % 4;
        }

        // y의 좌표
        r += dy[dir], c += dx[dir];

        vector<vector<int> > calc_window = Window_Calc(window[dir], board[r][c]);

        for(int i = r - 2; i <= r + 2; i++) {
            for(int j = c - 2; j <= c + 2; j++) {
                if(i < 0 || i >= N || j < 0 || j >= N) {
                    answer += calc_window[i - (r - 2)][j - (c - 2)];
                }
                else {
                    board[i][j] += calc_window[i - (r - 2)][j - (c - 2)] > 0 ? calc_window[i - (r - 2)][j - (c - 2)] : 0;
                }
            }
        }
        dist_count++;
    }
    
    cout << answer << endl;
    
    return 0;
}