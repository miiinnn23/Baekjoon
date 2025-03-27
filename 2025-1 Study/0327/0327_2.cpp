#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

int N, M;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<vector<int> > map;

int solution(int r, int c, int dir);

int main(void) {
    cin >> N >> M;
    int r, c, dir;
    cin >> r >> c >> dir;

    map.resize(N, vector<int>(M));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];

    cout << solution(r, c, dir) << endl;
    return 0;
}

int solution(int r, int c, int dir) {
    int count = 0;

    while(true) {
        if(map[r][c] == 0) {
            count++;
            map[r][c] = 2;
        }

        // 다음 칸 이동
        bool flag = false;
        for(int i = 3; i >= 0; i--) {
            int head = (dir + i) % 4;
            if(map[r + dy[head]][c + dx[head]] == 0) {
                dir = head;
                flag = true;
                break;
            }
        }
        
        if(flag) {
            r += dy[dir];
            c += dx[dir];
        }
        else {
            r -= dy[dir];
            c -= dx[dir];
            if(r < 0 || r >= N || c < 0 || c >= M || map[r][c] == 1) break;
        }
    }

    return count;
}