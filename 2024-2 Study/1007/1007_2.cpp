#include <iostream>
#define MAX 30

using namespace std;


int n;
int draw[MAX][MAX] = { 0 };
int temp[MAX][MAX] = { 0 };

int group[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
int group_count = 0;
int group_idx[MAX * MAX + 1] = { 0 };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void Rotate();
void SubRotate(int y, int x);

void DFS(int y, int x);
int MakeScore();

void Print();

int main(void) {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> draw[i][j];
        }
    }

    int sum = 0;
    for(int a = 0; a < 4; a++) {
        // 1. DFS -> 그룹핑
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        // 변수 초기화!!
        group_count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) { // 처음 발견한 그룹인 경우
                    visited[i][j] = true;
                    group_count++;
                    group[i][j] = group_count;
                    group_idx[group_count] = 1;
                    DFS(i, j);
                }
            }
        }
    
        sum += MakeScore();
        
        // 2. 회전
        Rotate();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = 0;
            }
        }
    }

    cout << sum << endl;
    
    return 0;
}

void Rotate() {
    // 십자가모양 반시계방향 90° 회전
    int k = n / 2;

    for(int i = 0; i < n; i++) {
        temp[i][k] = draw[k][n - i - 1]; // horizontal -> vertical
        temp[k][i] = draw[i][k]; // vertical -> horizontal
    }

    // 정사각형 시계방향 90° 회전
    SubRotate(0, 0);
    SubRotate(k + 1, 0);
    SubRotate(0, k + 1);
    SubRotate(k + 1, k + 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            draw[i][j] = temp[i][j];
        }
    }
}

void SubRotate(int y, int x) {
    int k = n / 2;

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            temp[i + y][j + x] = draw[y + k - j - 1][i + x];
        }
    }

}

void DFS(int y, int x) {
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n) continue;
        if(!visited[y + dy[i]][x + dx[i]] && draw[y][x] == draw[y + dy[i]][x + dx[i]]) {
            visited[y + dy[i]][x + dx[i]] = true;
            group[y + dy[i]][x + dx[i]] = group_count;
            group_idx[group_count]++;
            DFS(y + dy[i], x + dx[i]);
        }
    }
}

int MakeScore() {
    int score = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if(y < 0 || y >= n || x < 0 || x >= n) continue;
                if(group[i][j] != group[y][x]) {
                    int group1 = group[i][j], group2 = group[y][x];
                    // 그룹 1에 속한 칸의 수, 그룹 2에 속한 칸의 수
                    int count1 = group_idx[group1], count2 = group_idx[group2];
                    // 그룹 1을 이루고 있는 숫자 값, 그룹 2를 이루고 있는 숫자 값
                    int num1 = draw[i][j], num2 = draw[y][x];

                    // 그룹 a와 그룹 b가 서로 맞닿아 있는 변의 수 * 2 만큼 연산됨
                    score += (count1 + count2) * num1 * num2;
                }
            }
        }
    }
    return score / 2;
}

void Print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << draw[i][j] << "\t";
        }
        cout << endl << endl;
    }
}