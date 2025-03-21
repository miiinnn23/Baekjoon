#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001

using namespace std;

bool visited[MAX] = { false };
bool cycle[MAX] = { false };
int cnt = 0;

void DFS(int node, vector<int>& student) {
    int next = student[node];
    
    if(!visited[next]) {
        visited[next] = true;
        DFS(next, student);
    }
    else if(!cycle[next]) {
        int temp = next;
        while(temp != node) {
            cnt++;
            temp = student[temp];
        }
        cnt++;
    }
    cycle[node] = true;
}

int main(void) {
    int T, n;
    cin >> T;

    for(int iter = 0; iter < T; iter++) {
        cin >> n;
        
        cnt = 0;
        vector<int> student(n + 1, 0);
        memset(visited, false, n + 1);
        memset(cycle, false, n + 1);
        
        for(int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) DFS(i, student);
        }
        cout << n - cnt << endl;
    }
    return 0;
}