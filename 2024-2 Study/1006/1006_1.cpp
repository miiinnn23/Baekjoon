#include <iostream>
#include <queue>
#define MAX 16

using namespace std;

int n;
int map[MAX][MAX] = { 0 };

// 영양제의 이동 방향
int moveX[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int moveY[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

// 대각선 이동 방향
int dx[] = { -1, 1, -1, 1 }; 
int dy[] = { 1, 1, -1, -1 };

int main(void) {
    int m;
    int d, p;

    // 변수 입력
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 영양제 위치 초기화
    queue<pair<int, int> > potion;

    potion.push(make_pair(n - 1, 1));
    potion.push(make_pair(n - 1, 0));
    potion.push(make_pair(n - 2, 1));
    potion.push(make_pair(n - 2, 0));

    for(int i = 0; i < m; i++) {
        int d, p;
        cin >> d >> p;

        // 1. 영양제 이동
        int len = potion.size();
        
        bool visited[MAX][MAX] = { false };

        for(int j = 0; j < len; j++) {
            int y = potion.front().first;
            int x = potion.front().second;
            
            y = (y + p * moveY[d - 1] + n) % n;
            x = (x + p * moveX[d - 1] + n) % n;

            // 2. 투입 후 사라짐
            map[y][x]++;
            visited[y][x] = true;

            potion.pop();
            potion.push(make_pair(y, x));
        }

        // 3. 대각선 인접 방향 확인 -> 나무 높이 성장
        for(int j = 0; j < len; j++) {
            int y = potion.front().first;
            int x = potion.front().second;

            int height = 0;
            for(int k = 0; k < 4; k++) {
                if(y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= n) continue;
                
                if(map[y + dy[k]][x + dx[k]] > 0) height++;
            }
            map[y][x] += height;
            
            potion.pop();
        }

        // 4. 높이 2 이상 나무 -> 2만큼 베어냄, 그 자리에 영양제 심음
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(!visited[j][k] && map[j][k] >= 2) {
                    map[j][k] -= 2;
                    potion.push(make_pair(j, k));
                }
            }
        }

    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            count += map[i][j];
        }
    }

    cout << count << endl;
    return 0;
}