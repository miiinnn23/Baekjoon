#include <iostream>
#include <vector>
#include <climits>
#define MAX 21

using namespace std;

int N, answer = INT_MAX;
bool visited[MAX] = { false };
vector<vector<int> > graph;

void DFS(int num, int count);

int main(void) {
    cin >> N;

    graph.resize(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j= 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    DFS(0, 0);
    cout << answer << endl;
    return 0;
}

void DFS(int num, int count) {
    if(count == N / 2) {
        int start = 0, link = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i] && visited[j]) start += graph[i][j];
                if(!visited[i] && !visited[j]) link += graph[i][j];
            }
        }
        
        int diff = start > link ? start - link : link - start;
        answer = answer > diff ? diff : answer;
        return;
    }
    else {
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                DFS(i, count + 1);
                visited[i] = false;
            }
        }
    }
}