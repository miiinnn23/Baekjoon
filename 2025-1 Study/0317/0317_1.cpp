#include <iostream>
#include <string>
#include <vector>
#define MAX 101

using namespace std;

bool visited[MAX] = { false };
int cnt[MAX] = { 0 };

// 진짜 한줄씩 끊어가면서 해결
void DFS(int start, int cut, int node, vector<vector<int> > wires) {
    for(int i = 0; i < wires[node].size(); i++) {
        int next = wires[node][i];
        if(!visited[next] && next != cut) {
            cnt[start]++;
            visited[node] = true;
            DFS(start, cut, next, wires);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    vector<vector<int> > graph(n + 1);
    for(auto& i : wires) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }

    int min = MAX;
    
    for(auto& i : wires) {
        memset(cnt, 1, (n + 1) * sizeof(int));
        memset(visited, false, n + 1);
        DFS(i[0], i[1], i[0], graph);
        DFS(i[1], i[0], i[1], graph);

        int diff = cnt[i[0]] - cnt[i[1]] > 0 ? cnt[i[0]] - cnt[i[1]] : cnt[i[1]] - cnt[i[0]];
        min = diff < min ? diff : min;
    }

    return min;
}

int main(void) {
    int n;
    vector<vector<int> > wires;

    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        wires.push_back(temp);
    }

    cout << solution(n, wires) << "\n";
    return 0;
}

/*

9
1 3 2 3 3 4 4 5 4 6 4 7 7 8 7 9

*/