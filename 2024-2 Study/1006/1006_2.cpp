#include <iostream>
#include <vector>
#include <map>
#define MAX 21

using namespace std;

int n;
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };
int loc[MAX][MAX] = { 0 };

void ride(vector<vector<int> > friends);
int make_score(vector<vector<int> > friends, map<int, int> dict);

int main(void) {
    cin >> n;

    // 입력
    vector<vector<int> > friends(n * n, vector<int> (5));
    map<int, int> dict;

    for(int i = 0; i < n * n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> friends[i][j];
        }
        dict[friends[i][0]] = i;
    }
    // 탑승
    ride(friends);
    
    int score = make_score(friends, dict);

    cout << score << endl;
 
    return 0;
}

void ride(vector<vector<int> > friends) {
    for(int i = 0; i < n * n; i++) {
        vector<pair< int, int > > check_0;
        for(int j = 0; j < n * n; j++) {
            int y = j / n;
            int x = j % n;
            if(loc[y][x] == 0) check_0.push_back(make_pair(y, x));
        }

        // 비어있는 칸이 단 한 칸일 경우
        if(check_0.size() == 1)  {
            int y = check_0[0].first;
            int x = check_0[0].second;
            loc[y][x] = friends[i][0];
            continue;
        }


        // 1. 전체 칸에 좋아하는 친구가 있는지 확인
        vector<pair<int, int> > check_1;
        int len = check_0.size();
        int max_count = -1;

        
        for(int j = 0; j < len; j++) {
            int y = check_0[j].first;
            int x = check_0[j].second;
            
            int neighbor_count = 0;
            for(int k = 0; k < 4; k++) {
                if(y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= n) continue;
                for(int l = 1; l < 5; l++) {
                    if(loc[y][x] == 0 && loc[y + dy[k]][x + dx[k]] == friends[i][l]) neighbor_count++;
                }
            }

            if(neighbor_count > max_count) max_count = neighbor_count;
        }

        for(int j = 0; j < len; j++) {
            int y = check_0[j].first;
            int x = check_0[j].second;

            int neighbor_count = 0;
            for(int k = 0; k < 4; k++) {
                if(y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= n) continue;
                for(int l = 1; l < 5; l++) {
                    if(loc[y][x] == 0 && loc[y + dy[k]][x + dx[k]] == friends[i][l]) neighbor_count++;
                }
            }

            if(neighbor_count == max_count) check_1.push_back(make_pair(y, x));
        }

        // 하나만 있는 경우 -> 바로 찾은 경우
        if(check_1.size() == 1) {
            int y = check_1[0].first;
            int x = check_1[0].second;
            loc[y][x] = friends[i][0];
            continue;
        }


        // 2. 인접칸 중 비어있는 칸의 수가 가장 많은 곳 확인
        vector<pair<int, int> > check_2;
        max_count = -1;
        len = check_1.size();

        // 2-1. 인접칸 중 비어있는 칸의 최댓값 확인
        for(int j = 0; j < len; j++) {
            int y = check_1[j].first;
            int x = check_1[j].second;

            int adjacency_count = 0;
            for(int k = 0; k < 4; k++) {
                if(y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= n) continue;
                if(loc[y + dy[k]][x + dx[k]] == 0) adjacency_count++;
            }

            if(adjacency_count > max_count) max_count = adjacency_count;
        }

        // 2-2. 인접칸 중 비어있는 칸이 최댓값인 경우 추가
        for(int j = 0; j < len; j++) {
            int y = check_1[j].first;
            int x = check_1[j].second;

            int adjacency_count = 0;
            for(int k = 0; k < 4; k++) {
                if(y + dy[k] < 0 || y + dy[k] >= n || x + dx[k] < 0 || x + dx[k] >= n) continue;
                if(loc[y + dy[k]][x + dx[k]] == 0) adjacency_count++;
            }

            if(adjacency_count == max_count) check_2.push_back(make_pair(y, x));
        }

        if(check_2.size() == 1) {
            int y = check_2[0].first;
            int x = check_2[0].second;
            loc[y][x] = friends[i][0];
            continue;
        }

        int y = check_2[0].first;
        int x = check_2[0].second;

        loc[y][x] = friends[i][0];
    }
}

int make_score(vector<vector<int> > friends, map<int, int> dict) {
    int sum = 0;
    int score[] = { 0, 1, 10, 100, 1000 };

    for(int i = 0; i < n * n; i++) {
        int y = i / n;
        int x = i % n;
        int t = dict[loc[y][x]];

        int neighbor_count = 0;
        for(int j = 0; j < 4; j++) {
            if(y + dy[j] < 0 || y + dy[j] >= n || x + dx[j] < 0 || x + dx[j] >= n) continue;
            for(int l = 1; l < 5; l++) {
                if(loc[y + dy[j]][x + dx[j]] == friends[t][l]) neighbor_count++;
            }
        }

        sum += score[neighbor_count];
    }
    return sum;
}