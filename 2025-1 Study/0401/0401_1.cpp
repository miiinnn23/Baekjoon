#include <iostream>
#include <vector>
#include <climits>
#define MAX 14

using namespace std;

int N, M;
int answer = INT_MAX;

int dist(int r1, int c1, int r2, int c2) { return abs(r1 - r2) + abs(c1 - c2); }
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
vector<pair<int, int> > cord;
bool visited[MAX] = { false };

void DFS(int index, int count);
void dist_calc();

int main(void) {
    cin >> N >> M;
    vector<vector<int> > map(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back(pair(i, j));
            if(map[i][j] == 2) chicken.push_back(pair(i, j));
        }
    }

    DFS(0, 0);

    cout << answer << endl;
    return 0;
}

void DFS(int index, int count) {
    if(count == M) {
        dist_calc();
    }
    else {
        for(int i = index; i < chicken.size(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                cord.push_back(chicken[i]);
                DFS(i, count + 1);
                cord.pop_back();
                visited[i] = false;
            }
        }
    }
}

void dist_calc() {
    int chicken_dist = 0;

    for(int i = 0; i < house.size(); i++) {
        int min_dist = INT_MAX;
        for(int j = 0; j < M; j++) {
            int temp_dist = dist(house[i].first, house[i].second, cord[j].first, cord[j].second);
            min_dist = min_dist > temp_dist ? temp_dist : min_dist;
        }
        chicken_dist += min_dist;
    }

    answer = answer > chicken_dist ? chicken_dist : answer;
}