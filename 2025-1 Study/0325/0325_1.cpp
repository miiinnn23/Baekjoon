#include <iostream>
#include <vector>
#include <deque>
#define MAX 102

using namespace std;

int N, K, L;
int apple[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };

vector<pair<int, char> > change_dir;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int game();
void print_snake();

int main(void) {
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        apple[r][c] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        change_dir.push_back(make_pair(time, dir));
    }
    
    cout << game() << endl;
    return 0;
}

int game() {
    int time = 0;
    int time_index = 0;
    int dir = 0;

    deque<pair<int, int> > snake;
    
    snake.push_back({1, 1});
    visited[1][1] = true;
    while(true) {
        time++;

        int next_r = snake.front().first + dy[dir];
        int next_c = snake.front().second + dx[dir];
        cout << next_r << ", " << next_c << endl;

        if(next_r < 1 || next_r > N || next_c < 1 || next_c > N || visited[next_r][next_c]) break; // out of range

        snake.push_front({next_r, next_c}); // 사과가 있으면 길이 1 증가(머리만 증가)

        if(apple[next_r][next_c] != 1) {
            visited[snake.back().first][snake.back().second] = false;
            snake.pop_back();
        }
        else { // 사과 먹었으면 없앰
            apple[next_r][next_c] = 0;
        }

        visited[next_r][next_c] = true;
        print_snake();

        if(time == change_dir[time_index].first) {
            dir = change_dir[time_index].second == 'L' ? (dir + 1) % 4 : (dir + 3) % 4;
            time_index++;
        }
    }
    
    return time;
}

void print_snake() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(apple[i][j] == 1) {
                cout << "o ";
            }
            else if(visited[i][j]) {
                cout << "- ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}