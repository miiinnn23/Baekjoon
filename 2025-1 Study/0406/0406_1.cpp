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
    for(int i = 0; i < shark.size(); i++) {
        if(shark[i].Size < 0) continue;
        // 1, 2: 상하, 3, 4: 좌우
        int speed = shark[i].Speed;
        int dir = shark[i].Dir;
        
        if(dir < 3) speed %= 2 * (R - 1);
        else speed %= 2 * (C - 1);
        
        int r = shark[i].R, c = shark[i].C;
        for(int s = 0; s < speed; s++) {
            if(r + dy[dir] < 1 || r + dy[dir] > R || c + dx[dir] < 1 || c + dx[dir] > C) {
                r -= dy[dir];
                c -= dx[dir];
                if(dir < 3) dir == 1 ? dir = 2 : dir = 1;
                else dir == 3 ? dir = 4 : dir = 3;
            }
            else {
                r += dy[dir], c += dx[dir];
            }
        }
        shark[i].R = r, shark[i].C = c;
        shark[i].Dir = dir;

        Map[shark[i].R][shark[i].C].push_back(shark[i]);
    }
}