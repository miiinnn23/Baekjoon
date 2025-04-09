#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

struct FireBall {
    int R;
    int C;
    int Mass;
    int Dir;
    int Speed;
};

int N, M, K;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<FireBall> fireball;
vector<FireBall> Map[MAX][MAX];

void Command();
void Movement();
void Fireball_sum();

int main(void) {
    cin >> N >> M >> K;
    
    fireball.resize(M);

    for(int i = 0; i < M; i++) {
        cin >> fireball[i].R >> fireball[i].C >> fireball[i].Mass >> fireball[i].Speed >> fireball[i].Dir;
        // Map[fireball[i].R][fireball[i].C].push_back(fireball[i]);
    }

    Command();

    return 0;
}

void Command() {
    for(int cmd = 0; cmd < K; cmd++) {
        // 이동 전 map 초기화
        for(int i = 0; i < fireball.size(); i++) {
            if(fireball[i].Mass < 0) continue; // 이거 빼도 될수도??
            int r = fireball[i].R, c = fireball[i].C;
            Map[r][c].clear();
        }

        // 파이어볼 이동
        Movement();

        // 파이어볼 합체
        Fireball_sum();
    }

    int sum = 0;
    for(int i = 0; i < fireball.size(); i++) {
        if(fireball[i].Mass > 0) {
            sum += fireball[i].Mass;
        }
    }
    cout << sum;
}

void Movement() {
    for(int f = 0; f < fireball.size(); f++) {
        if(fireball[f].Mass <= 0) continue; // fireball 소멸

        int r = fireball[f].R, c = fireball[f].C;
        int dir = fireball[f].Dir;

        int movement_r = r + (fireball[f].Speed % N) * dy[dir];
        int movement_c = c + (fireball[f].Speed % N) * dx[dir];

        int start_r = 0, start_c = 0;
        if(dx[dir] < 0) start_c = N;
        if(dy[dir] < 0) start_r = N;

        fireball[f].R = (start_r + movement_r) % N == 0 ? N : (start_r + movement_r) % N;
        fireball[f].C = (start_c + movement_c) % N == 0 ? N : (start_c + movement_c) % N;
        Map[fireball[f].R][fireball[f].C].push_back(fireball[f]);
    }
}

void Fireball_sum() {
    vector<FireBall> new_fireball;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(Map[i][j].size() == 1) new_fireball.push_back(Map[i][j][0]);

            else if(Map[i][j].size() > 1) {
                // 파이어볼 합체
                int mass_sum = 0, speed_sum = 0;
                int size = Map[i][j].size();
                int mod = Map[i][j][0].Dir % 2;
                bool flag = true;

                for(int k = 0; k < size; k++) {
                    mass_sum += Map[i][j][k].Mass;
                    speed_sum += Map[i][j][k].Speed;
                    Map[i][j][k].Mass = -1;

                    if(mod != (Map[i][j][k].Dir % 2)) flag = false;
                }

                if(flag) {
                    for(int k = 0; k < 4; k++)
                        new_fireball.push_back({i, j, mass_sum / 5, 2 * k, speed_sum / size});
                }
                else {
                    for(int k = 0; k < 4; k++)
                        new_fireball.push_back({i, j, mass_sum / 5, 2 * k + 1, speed_sum / size});
                }
            }
            else continue;
        }
    }
    fireball.swap(new_fireball);
}