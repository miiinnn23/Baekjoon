#include <iostream>
#include <string>
#include <vector>
#define MAX 201

using namespace std;

int visited[MAX] = { 0 };

void DFS(vector<vector<int>> computers, int node) {
    visited[node] = 1;
    for(int i = 0; i < computers[node].size(); i++) {
        if(i == node) continue;
        
        if(computers[node][i] == 1 && visited[i] == 0) {
            DFS(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    int len = computers.size();
    for(int i = 0; i < len; i++) {
        if(visited[i] == 0) {
            DFS(computers, i);
            answer++;
        }
    }
    return answer;
}

int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> computers;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        computers.push_back(temp);
    }

    cout << solution(n, computers) << endl;
    return 0;
}