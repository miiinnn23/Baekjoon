#include <iostream>
#include <vector>
#define MAX 102
using namespace std;

int n, m;

// (1~100, 1~100)
bool tree[MAX][MAX] = { false };

bool Distance(int x1, int y1, int x2, int y2) {
    int x = (x1 - x2) > 0 ? x1 - x2 : x2 - x1;
    int y = (y1 - y2) > 0 ? y1 - y2 : y2 - y1;

    return (x + y) <= 3 ? true : false;
}

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };


int main(void) {
    int h, k;

    // 변수 입력
    cin >> n >> m >> h >> k;
    
    // 도망자 선언 및 입력
    vector<vector<int> > runner(m, vector<int> (3));

    for(int i = 0; i < m; i++) {
        cin >> runner[i][0] >> runner[i][1] >> runner[i][2];
    }

    // 나무위치 bool로 표현
    for(int i = 0; i < h; i++) {
        int x, y;
        cin >> y >> x;
        tree[y][x] = true;
    }
    
    // 술래는 정중앙에서 시작
    int tag[] = { n / 2 + 1, n / 2 + 1 };

    int rotation, before, mv, move_count;
    int sum = 0;
    
    for(int i = 0; i < k; i++) {
        // 도망자 이동 차례
        for(int j = 0; j < m; j++) {
            // 거리가 3 이하인 경우만 이동
            if(Distance(runner[j][0], runner[j][1], tag[0], tag[1])) {
                int dir = runner[j][2];

                int x = runner[j][1];
                int y = runner[j][0];

                // 벽에 부딪혔을 경우 이동방향 전환
                if(x + dx[dir] < 1 || x + dx[dir] > n || y + dy[dir] < 1 || y + dy[dir] > n) {
                    dir = (dir - 2) < 0 ? dir + 2 : dir - 2;
                    runner[j][2] = dir;
                }

                // 술래가 이동하려는 위치에 있는 경우 이동하지 않음
                if(x + dx[dir] == tag[1] && y + dy[dir] == tag[0]) continue;
                else {
                    runner[j][1] = x + dx[dir];
                    runner[j][0] = y + dy[dir];
                }
            }
        }
        
        // 술래 이동 차례
        int t = i % (2 * n * n - 2);

        if(t == 0) {
            rotation = 0; before = -1, mv = 1; move_count = 0;
        }

        tag[0] += dy[rotation];
        tag[1] += dx[rotation];
        
        if(t < n * n - 1) {
            if(t == before + mv) {
                move_count++;
                before = t;
                rotation = (++rotation) % 4;
            }

            if(move_count == 2) {
                move_count = 0;
                mv++;
            }

            if(t == n * n - 2) {
                mv--;
                rotation = 2;
                move_count = -1;
                before = t;
            }
        }
        else {
            if(t == before + mv) {
                move_count++;
                before = t;
                rotation = (--rotation + 4) % 4;
            }
            
            if(move_count == 2) {
                move_count = 0;
                mv--;
            }
        }

        // 점수내기..ㅋㅋㅋㅋ
        int score = 0;

        int x = tag[1];
        int y = tag[0];
        
        vector<int> erase_num;
        for(int j = 0; j < m; j++) {
            int runner_x = runner[j][1];
            int runner_y = runner[j][0];

            if(!tree[runner_y][runner_x]) {
                if((x == runner_x && y == runner_y) || (x + dx[rotation] == runner_x && y + dy[rotation] == runner_y) || (x + 2 * dx[rotation] == runner_x && y + 2 * dy[rotation] == runner_y)) {
                    score++;
                    erase_num.push_back(j);
                }
            }
        }
        
        for(int j = erase_num.size() - 1; j >= 0; j--) {
            runner.erase(runner.begin() + erase_num[j]);
            m--;
        }
    
        sum += (i + 1) * score;
    }

    cout << sum << endl;

    return 0;
}