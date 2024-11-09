#include <iostream>

#include <string> 
#include <vector>

#define MAX 13

using namespace std;

int visited[MAX] = { 0 };
int N;
int answer = 0;

bool is_placed(int queen) {
    for(int i = 0; i < queen; i++) { // 0부터 현재 queen 위로만 탐색 진행
        if(visited[i] == visited[queen] || queen - i == abs(visited[queen] - visited[i])) return false;
    }
    return true;
}

void DFS(int queen) {
    if(queen == N) {
        answer++;
        return;
    }

    for(int i = 0; i < N; i++) {
        visited[queen] = i;
        if(is_placed(queen)) {
            DFS(queen + 1);
        }
    }
}

int solution(int n) {
    N = n;
    DFS(0);
    return answer;
}

int main(void) {
    int n;
    cin >> n;
    cout << solution(n) << endl;
}