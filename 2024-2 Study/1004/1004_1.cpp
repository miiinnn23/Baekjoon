#include <iostream>
#include <queue>
using namespace std;
#define MAX 21

int map[MAX][MAX];

int n;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int BFS(int start_x, int start_y);

int main(void) {
    int m;
    cin >> n >> m;

    // 1. 입력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    // 2. 필요한 지역 변수 초기화
    int score = 0;
    int movement = 0;
    int u = 1, f = 2, r = 3;
    int dice[] = { u, f, r };

    int x = 0, y = 0;

    for(int i = 0; i < m; i++) {
        x += dx[movement];
        y += dy[movement];
        
        score += BFS(y, x);

        // 3. 주사위 움직임 규칙 설계
        // dice[0] : 윗면(u), dice[1] : 앞면(f), dice[2] : 옆면(r)
        u = dice[0], f = dice[1], r = dice[2];
        if(movement == 0) { dice[0] = 7 - r; dice[1] = f; dice[2] = u; }
        else if(movement == 1) { dice[0] = 7 - f; dice[1] = u; dice[2] = r; }
        else if(movement == 2) { dice[0] = r; dice[1] = f;dice[2] = 7 - u; }
        else { dice[0] = f; dice[1] = 7 - u; dice[2] = r; }


        // 4. 다음 움직임 결정
        if( (7 - dice[0]) > map[y][x] ) movement = (movement + 1) % 4;
        else if ( (7 - dice[0]) < map[y][x] ) movement = (movement - 1 + 4) % 4;

        if(x + dx[movement] < 0 || x + dx[movement] >= n || y + dy[movement] < 0 || y + dy[movement] >= n) {
            movement = (movement + 2) % 4;
        }
    }
    
    cout << score << endl;
    return 0;
}

int BFS(int start_x, int start_y) {
    // 점수 계산 용 BFS
    int sum = 0;
    queue<pair<int, int> > q;
    bool visited[MAX][MAX] = { false };

    q.push(pair<int, int> (start_x, start_y));
    int target = map[start_x][start_y];
    visited[start_x][start_y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        sum += map[x][y];

        q.pop();
        for(int i = 0; i < 4; i++) {
            // 바깥을 벗어나는 조건 설정
            if(x + dy[i] < 0 || x + dy[i] >= n || y + dx[i] < 0 || y + dx[i] >= n) continue;
            if(!visited[x + dy[i]][y + dx[i]] && map[x + dy[i]][y + dx[i]] == target) {
                visited[x + dy[i]][y + dx[i]] = true;
                q.push(pair<int, int> (x + dy[i], y + dx[i]));
            }
        }
    }
    // 점수 반환
    return sum;
}