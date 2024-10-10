#include <iostream>
#include <vector>
#include <queue>
#define MAX 11

using namespace std;

// 시간초과 코드 ㅠㅠ
// 매번 NxM에서 탐색하는게 아니라 해설처럼 정렬하는 방법을 써야 시간초과가 안나지않을까..

int n, m;
int coord[MAX][MAX];
int attack[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
int route_x[MAX][MAX], route_y[MAX][MAX];
bool attacked[MAX][MAX] = { false };

int min_damage_pos[] = { -1, -1 };
int max_damage_pos[] = { -1, -1 };

// 직선 이동 방향(우, 하, 좌, 상)
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 대각선 이동 방향(순서무관)
int dx_d[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy_d[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

bool IsDestroyed(int i, int j) { return coord[i][j] == 0; }
void Select(int turn);
void Attack(int turn);
bool LasorAttack();
void BombAttack();

int main(void) {
    int k;

    // 변수 입력
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> coord[i][j];
        }
    }
    
    for(int i = 0; i < k; i++) {
        // 부서지지 않은 포탑이 1개가 된다면 즉시 중지
        int count = 0;
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                if(!IsDestroyed(y, x)) count++;
            }
        }
        if(count < 2) break;

        // 변수 초기화
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                visited[y][x] = false;
                attacked[y][x] = false;
                route_x[y][x] = 0;
                route_y[y][x] = 0;
            }
        }

        Select(i);
        Attack(i);

        coord[min_damage_pos[0]][min_damage_pos[1]] += (n + m);
        bool play = LasorAttack();

        if(!play) BombAttack();

        for(int j = 0; j < n; j++) {
            for(int l = 0; l < m; l++) {
                if(attacked[j][l]) continue;
                if(IsDestroyed(j, l)) continue;
                coord[j][l]++;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(max < coord[i][j]) max= coord[i][j];
        }
    }

    cout << max << endl;
    return 0;
}

void Select(int turn) {
    int min_damage = 5001;
    
    // 1. 공격자 선정
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 1-1. 부서지지 않았으면서 가장 공격력이 약한 포탑 선정
            if(coord[i][j] < min_damage && !IsDestroyed(i, j)) {
                min_damage = coord[i][j];
                min_damage_pos[0] = i;
                min_damage_pos[1] = j;
            }
        }
    }

    // 1-2~4. 만약 공격력이 가장 낮은 포탑이 2개 이상일 경우
    vector<pair<int, int> > temp;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(coord[i][j] == min_damage) {
                temp.push_back(make_pair(i, j));
            }
        }
    }

    if(temp.size() > 1) {
        // 1-2. 제일 최근에 공격한 포탑
        if(turn > 0) {
            int turn_max = 0;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(turn_max < attack[i][j]) {
                        turn_max = attack[i][j];
                        min_damage_pos[0] = i;
                        min_damage_pos[1] = j;
                    }
                }
            }

        }
        else {
            int row_col_sum = -1;
            // 1-3. 행과 열의 합이 가장 큰 포탑
            for(int i = 0; i < temp.size(); i++) {
                int temp_sum = temp[i].first + temp[i].second;
                if(temp_sum > row_col_sum) row_col_sum = temp_sum;
            }

            for(int i = temp.size() - 1; i >= 0; i--) {
                int temp_sum = temp[i].first + temp[i].second;
                if(temp_sum != row_col_sum) temp.erase(temp.begin() + i);
            }
            
            // 1-4. 열 값이 가장 큰 포탑
            if(temp.size() > 1) {
                int col_max = -1;

                for(int i = 0; i < temp.size(); i++) {
                    if(temp[i].second > col_max) {
                        col_max = temp[i].second;
                        min_damage_pos[0] = temp[i].first;
                        min_damage_pos[1] = temp[i].second;
                    }
                }
            }
            
            else {
                min_damage_pos[0] = temp[0].first;
                min_damage_pos[1] = temp[0].second;
            }
        }
    }
    
    attack[min_damage_pos[0]][min_damage_pos[1]] = turn;
    attacked[min_damage_pos[0]][min_damage_pos[1]] = true;
}

void Attack(int turn) {
    int max_damage = 0;
    
    // 1. 공격 대상 선정
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 1-1. 가장 공격력이 강한 포탑 선정
            if(coord[i][j] > max_damage) {
                max_damage = coord[i][j];
                max_damage_pos[0] = i;
                max_damage_pos[1] = j;
            }
        }
    }

    // 1-2~4. 만약 공격력이 가장 높은 포탑이 2개 이상일 경우
    vector<pair<int, int> > temp;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(coord[i][j] == max_damage) {
                temp.push_back(make_pair(i, j));
            }
        }
    }

    if(temp.size() > 1) {
        // 1-2. 공격한지 가장 오래된 포탑
        int turn_min = 1001;
        
        for(int i = 0; i < temp.size(); i++) {
            int y = temp[i].first;
            int x = temp[i].second;

            if(turn_min > attack[y][x]) turn_min = attack[y][x];
        }

        for(int i = temp.size() - 1; i >= 0; i--) {
            int y = temp[i].first;
            int x = temp[i].second;

            if(turn_min != attack[y][x]) temp.erase(temp.begin() + i);
        }
        

        if(temp.size() > 1) {
            int row_col_sum = 21;

            // 1-3. 행과 열의 합이 가장 작은 포탑
            for(int i = 0; i < temp.size(); i++) {
                int temp_sum = temp[i].first + temp[i].second;
                if(temp_sum < row_col_sum) row_col_sum = temp_sum;
            }

            for(int i = temp.size() - 1; i >= 0; i--) {
                int temp_sum = temp[i].first + temp[i].second;
                if(temp_sum != row_col_sum) temp.erase(temp.begin() + i);
            }

            
            // 1-4. 열 값이 가장 작은 포탑
            if(temp.size() > 1) {
                int col_min = 11;

                for(int i = 0; i < temp.size(); i++) {
                    if(temp[i].second < col_min) {
                        col_min = temp[i].second;
                        min_damage_pos[0] = temp[i].first;
                        min_damage_pos[1] = temp[i].second;
                    }
                }
            }
            
            else {
                min_damage_pos[0] = temp[0].first;
                min_damage_pos[1] = temp[0].second;
            }
        }
        
        else {
            max_damage_pos[0] = temp[0].first;
            max_damage_pos[1] = temp[0].second;
        }
    }
}

bool LasorAttack() {
    int start_x = min_damage_pos[1];
    int start_y = min_damage_pos[0];

    queue<pair<int, int> > q;

    q.push(make_pair(start_y, start_x));
    visited[start_y][start_x] = true;

    bool can_attack = false;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        // 목표를 포착한 경우
        if(x == max_damage_pos[1] && y == max_damage_pos[0]) {
            can_attack = true;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int ny = (y + dy[i] + n) % n;
            int nx = (x + dx[i] + m) % m;

            if(IsDestroyed(ny, nx)) continue;

            if(!visited[ny][nx]) {
                visited[ny][nx] = true;
                route_x[ny][nx] = x;
                route_y[ny][nx] = y;
                q.push(make_pair(ny, nx));
            }
        }
    }

    // 공격 가능한 경우 레이저 공격
    if(can_attack) {
        int target_x = max_damage_pos[1];
        int target_y = max_damage_pos[0];

        int damage = coord[start_y][start_x];

        coord[target_y][target_x] = (coord[target_y][target_x] - damage) > 0 ? coord[target_y][target_x] - damage : 0;
        attacked[target_y][target_x] = true;

        int ex = route_x[target_y][target_x];
        int ey = route_y[target_y][target_x];
    

        while(true) {
            coord[ey][ex] = (coord[ey][ex] - (damage / 2)) > 0 ? (coord[ey][ex] - (damage / 2)) : 0;
            attacked[ey][ex] = true;

            int next_x = route_x[ey][ex];
            int next_y = route_y[ey][ex];

            ex = next_x;
            ey = next_y;

            if(ex == start_x && ey == start_y) break;
        }
    }

    return can_attack;
}

void BombAttack() {
    int x = max_damage_pos[1];
    int y = max_damage_pos[0];
    
    int start_x = min_damage_pos[1];
    int start_y = min_damage_pos[0];
    int damage = coord[start_y][start_x];

    // 타겟 공격
    coord[y][x] = (coord[y][x] - damage) > 0 ? coord[y][x] - damage : 0;
    attacked[y][x] = true;

    for(int i = 0; i < 8; i++) {
        int ny = (y + dy[i] + n) % n;
        int nx = (x + dx[i] + m) % m;

        // 공격 대상이 자기 자신일 경우 pass
        if(nx == start_x && ny == start_y) continue;

        coord[ny][nx] = (coord[ny][nx] - damage / 2) > 0 ? coord[ny][nx] - damage / 2 : 0;
        attacked[ny][nx] = true;
    }
}