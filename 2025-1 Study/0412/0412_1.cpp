#include <iostream>
#include <vector>
#include <queue>
#define MAX 51

using namespace std;

int N, M;

vector<vector<int> > A;
bool visited[MAX][MAX] = { false };

int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

queue<pair<int, int> > cloud;

int solution();
pair<int, int> movement(int r, int c, int dir, int speed);

int main(void) {
    cin >> N >> M;
    A = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> A[i][j];

    cloud.push({N, 1});
    cloud.push({N, 2});
    cloud.push({N - 1, 1});
    cloud.push({N - 1, 2});

    cout << solution();
    return 0;
}

int solution() {
    vector<vector<int>> temp(N + 1, vector<int>(N + 1, 0));

    for(int o = 0; o < M; o++) {
        int dir, speed;
        cin >> dir >> speed;

        // 1. 구름 이동
        int cloud_num = cloud.size();
        for(int i = 0; i < cloud_num; i++) {
            int r = cloud.front().first, c = cloud.front().second;
            pair<int, int> next = movement(r, c, dir, speed);

            int nr = next.first, nc = next.second;
            // cout << r << ", " << c << " -> " << nr << ", " << nc << endl;

            A[nr][nc]++; // 2. 구름이 있는 칸의 바구니에 저장된 물의 양 1 증가
            cloud.push({nr, nc});
            cloud.pop();
        }
        
        temp = A;
        for(int i = 0; i < cloud_num; i++) {
            int nr = cloud.front().first, nc = cloud.front().second;
            cloud.pop();    // 3. 구름 삭제
            if(!visited[nr][nc]) {
                // 4. 물복사버그
                int water = 0;
                for(int d = 2; d <= 8; d += 2) {
                    int dr = nr + dy[d], dc = nc + dx[d];
                    if(dr < 1 || dr > N || dc < 1 || dc > N) continue;
                    if(A[dr][dc] > 0) water++;
                }
                temp[nr][nc] += water;
                visited[nr][nc] = true;
            }
        }

        A.swap(temp);

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(visited[i][j]) {
                    visited[i][j] = false;
                    continue;
                }
                if(!visited[i][j] && A[i][j] >= 2) {
                    A[i][j] -= 2;
                    cloud.push({i, j});
                }
            }
        }
    }
    
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(A[i][j] >= 0) sum += A[i][j];
        }
    }

    return sum;
}

pair<int, int> movement(int r, int c, int dir, int speed) {
    int mv_r = r + (speed % N) * dy[dir];
    int mv_c = c + (speed % N) * dx[dir];

    if(mv_r > N) mv_r -= N;
    if(mv_c > N) mv_c -= N;
    if(mv_r <= 0) mv_r += N;
    if(mv_c <= 0) mv_c += N;

    return {mv_r, mv_c};
}