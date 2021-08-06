#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 100001

using namespace std;

int n, diameter, furthest;
vector<pair<int, int> > graph[MAX]; // <다음 노드, 거리>
bool visited[MAX];

void DFS(int vertex, int dist);

int main(void) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        while(true) {
            int b, c;
            scanf("%d", &b);

            if(b == -1) break;

            scanf("%d", &c);
            graph[a].push_back(pair<int, int>(b, c));
        }
    }

    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    diameter = 0;
    DFS(furthest, 0);

    printf("%d\n", diameter);
    return 0;
}

void DFS(int vertex, int dist) {
    if(visited[vertex]) return;
    visited[vertex] = true;

    if(diameter < dist) {
        diameter = dist;
        furthest = vertex;
    }
    for(int i = 0; i < graph[vertex].size(); i++) {
        DFS(graph[vertex][i].first, dist + graph[vertex][i].second);
    }
}