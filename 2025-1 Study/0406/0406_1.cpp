#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

struct Shark {
    int R;
    int C;
    int Size;
    int Speed;
    int Dir;
    int Index;
};

int R, C;
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, -1, 1, 0, 0 };

vector<Shark> shark;
vector<Shark> Map[MAX][MAX];

pair<int, int> move1D(int x, int s, int effectiveDir, int N) {
    if (N == 1) return {1, effectiveDir}; // 구간 크기 1이면 항상 1번 칸
    
    int period = 2 * (N - 1);  // 왕복 주기
    s %= period;             // 속력을 주기 내에서만 고려
    
    int offset;
    if (effectiveDir == +1) {
        // 정방향: x-1 (0-based)
        offset = x - 1;
        offset = (offset + s) % period;
    } else { // effectiveDir == -1
        // 역방향: (x-1)에서 s를 뺀다.
        offset = (x - 1) - s;
        // C++에서 음수 모듈로 보정:
        offset = (offset % period + period) % period;
    }
    
    int new_x, newEffective;
    if (offset < N) {
        new_x = offset + 1;  // 다시 1-based 좌표로 변환
        newEffective = +1;
    } else {
        new_x = period - offset + 1;
        newEffective = -1;
    }
    
    return {new_x, newEffective};
}

bool Compare(const Shark& a, const Shark& b) {
    if(a.Size > b.Size) return true;
    return false;
}

int Solution();
void Movement();

int main(void) {
    int num;
    cin >> R >> C >> num;
    
    shark.resize(num);
    for(int i = 0; i < num; i++) {
        cin >> shark[i].R >> shark[i].C >> shark[i].Speed >> shark[i].Dir >> shark[i].Size;
        shark[i].Index = i;
        Map[shark[i].R][shark[i].C].push_back(shark[i]);
    }

    cout << Solution() << endl;

    return 0;
}

int Solution() {
    int answer = 0;
    for(int time = 1; time <= C; time++) {
        cout << "Day " << time << endl;
        // 낚시꾼 이동
        for(int i = 1; i <= R; i++) {
            if(!Map[i][time].empty()) {
                int index = Map[i][time][0].Index;
                answer += Map[i][time][0].Size; // 가장 가까운 상어 잡음(어차피 한칸에 상어는 하나)
                shark[index].Size = -1;         // 상어죽음
                Map[i][time].pop_back();
                break;
            }
        }
        
        // 상어 이동 전 맵 초기화
        for(int i = 0; i < shark.size(); i++) {
            if(shark[i].Size < 0) continue;
            int r = shark[i].R, c = shark[i].C;
            Map[r][c].clear();
        }

        // 상어 이동
        Movement();

        // 더 큰 상어가 잡아먹는다 ~~
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                if(Map[i][j].size() > 1) {
                    sort(Map[i][j].begin(), Map[i][j].end(), Compare);
                    for(int k = Map[i][j].size() - 1; k >= 1; k--) {
                        cout << "사냥: " << Map[i][j][0].Size << " > " << Map[i][j][k].Size << endl;
                        int caught = Map[i][j][k].Index;
                        shark[caught].Size = -1;
                        Map[i][j].pop_back();
                    }
                }
                else continue;
            }
        }
    }

    return answer;
}

void Movement() {
    int period[2] = {2 * (R - 1), 2 * (C - 1)};
    
    for(int i = 0; i < shark.size(); i++) {
        if(shark[i].Size < 0) continue;
        // 1, 2: 상하, 3, 4: 좌우 -> 0: 상하이동, 1: 좌우이동
        cout << "(" << shark[i].R << ", " << shark[i].C << "), 이동방향: " << shark[i].Dir << " -> ";
        int shark_dir = (shark[i].Dir - 1) / 2 == 0 ? 0 : 1;

        // int offset = 0, speed = 0, moved = 0;
        // int new_pos, new_dir;
        // if(shark[i].Dir == 1 || shark[i].Dir == 2) {
        //     speed = shark[i].Speed % period[0];
        //     offset = shark[i].Dir == 2 ? shark[i].R - 1 : ((R - 1) - (shark[i].R - 1));
        //     moved = (offset + speed) % period[0];

        //     if(moved < R) {
        //         new_pos = moved + 1;
        //         new_dir = shark[i].Dir;
        //     }
        //     else {
        //         new_pos = period[0] - moved + 1;
        //         new_dir = shark[i].Dir == 1 ? 2 : 1;
        //     }
        //     shark[i].R = new_pos;
        //     shark[i].Dir = new_dir;
        // }
        // else {
        //     speed = shark[i].Speed % period[1];
        //     offset = shark[i].Dir == 3 ? shark[i].C - 1 : ((C - 1) - (shark[i].C - 1));
        //     moved = (offset + speed) % period[1];

        //     if(moved < C) {
        //         new_pos = moved + 1;
        //         new_dir = shark[i].Dir;
        //     }
        //     else {
        //         new_pos = period[1] - moved + 1;
        //         new_dir = shark[i].Dir == 3 ? 4 : 3;
        //     }
        //     shark[i].C = new_pos;
        //     shark[i].Dir = new_dir;
        // }

        if (shark[i].Dir == 1 || shark[i].Dir == 2) {
            int effectiveDir = (shark[i].Dir == 2) ? +1 : -1;  // 아래: +1, 위: -1
            auto res = move1D(shark[i].R, shark[i].Speed, effectiveDir, R);
            shark[i].R = res.first;
            // 새 효과적 방향을 실제 방향으로 변환:
            shark[i].Dir = (res.second == +1 ? 2 : 1);
        }
        // 가로 이동 (방향 3: 오른쪽, 4: 왼쪽)
        else if (shark[i].Dir == 3 || shark[i].Dir == 4) {
            int effectiveDir = (shark[i].Dir == 3) ? +1 : -1;  // 오른쪽: +1, 왼쪽: -1
            auto res = move1D(shark[i].C, shark[i].Speed, effectiveDir, C);
            shark[i].C = res.first;
            shark[i].Dir = (res.second == +1 ? 3 : 4);
        }
        cout << "(" << shark[i].R << ", " << shark[i].C << "), 이동방향 :" << shark[i].Dir << "\n";

        Map[shark[i].R][shark[i].C].push_back(shark[i]);
    }
}