#include <iostream>
#include <string>
#include <queue>
#define MAX 201

using namespace std;

int R, C, N;
string bomb_1[MAX], bomb_2[MAX];
queue<pair<int, int> > q;
void BFS();

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
    cin >> R >> C >> N;
    fflush(stdin);

    for(int i = 0; i < R; i++) {
        getline(cin, bomb_1[i]);
    }

    if(N % 2 == 0) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout << "O";
            }
            cout << "\n";
        }
    }
    else {
        for(int k = 0; k < (N + 1 / 2); k++) {
            for(int i = 0; i < R; i++) {
                bomb_2[i].clear();
                bomb_2[i].append(C, 'O');
                for(int j = 0; j < C; j++) {
                    if(bomb_1[i][j] == 'O') {
                        q.push(pair<int, int>(i, j));
                    }
                }
            }

            BFS();

            for(int i = 0; i < R; i++) {
                bomb_1[i].assign(bomb_2[i]);
            }
        }

        for(int i = 0; i < R; i++) {
            cout << bomb_2[i] << "\n";
        }
    }
    return 0;
}

void BFS() {
    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        
        bomb_2[y][x] = '.';
        q.pop();
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] < 0 || x + dx[i] > (C - 1) || y + dy[i] < 0 || y + dy[i] > (R - 1)) continue;
            if(bomb_2[y + dy[i]][x + dx[i]] == 'O') {
                bomb_2[y + dy[i]][x + dx[i]] = '.';
            }
        }
    }
}