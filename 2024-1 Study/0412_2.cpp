#include <iostream>
#include <string>
#include <vector>
#define MAX 9

using namespace std;

int answer = 0;
bool visited[MAX] = { false };

void DFS(int k, vector<vector<int>> dungeons, int count) {
    if(count > answer) answer = count;

    for(int i = 0; i < dungeons.size(); i++) {
        if(!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            DFS(k - dungeons[i][1], dungeons, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(k, dungeons, 0);
    return answer;
}

int main(void) {
    int k, n;
    cin >> k >> n;

    vector<vector<int>> dungeons(n, vector<int>(2, 0));
    
    for(int i = 0; i < n; i++) {
        cin >> dungeons[i][0] >> dungeons[i][1];
    }

    cout << solution(k, dungeons) << endl;

    return 0;
}