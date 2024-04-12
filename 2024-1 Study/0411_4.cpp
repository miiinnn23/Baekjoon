#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 20001

using namespace std;

bool visited[MAX] = { false };

int BFS(int start, vector<vector<int>> graph) {
    queue<int> q;
    vector<int> depth(graph.size(), 0);
    int maximum = 0, count = 0;

    q.push(start);
    visited[start] = true;
    depth[start] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
                depth[next] = depth[node] + 1;

                maximum = maximum < depth[next] ? depth[next] : maximum;
            }
        }
    }

    for(int i = 0; i < graph.size(); i++) {
        if(depth[i] == maximum) count++;
    }
    return count;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1, vector<int>());

    for(int i = 0; i < edge.size(); i++) {
        int start = edge[i][0];
        int end = edge[i][1];
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    answer = BFS(1, graph);

    return answer;
}

int main(void) {
    int N, V;
    cin >> N >> V;
    
    vector<vector<int>> edge(V, vector<int>(2, 0));
    for(int i = 0; i < V; i++) {
        cin >> edge[i][0] >> edge[i][1];
    }

    cout << solution(N, edge) << endl;
    return 0;
}