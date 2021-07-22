#include <cstdio>
#include <queue>
#define MAX 1001

using namespace std;

int Graph[MAX][MAX] = { 0 };
bool visited[MAX] = { false };

void BFS(int vertex, int V);
void DFS(int start, int V);

int main(void) {
    int v, e, start;
    scanf("%d %d %d", &v, &e, &start);
    
    for(int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Graph[a][b] = Graph[b][a] = 1;
    }

    DFS(start, v);
    for(int i = 0; i <= v; i++)
        visited[i] = false;

    printf("\n");
    BFS(start, v);
    return 0;
}

void DFS(int vertex, int V) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for(int i = 1; i <= V; i++) {
        if(visited[i] || Graph[vertex][i] == 0)
            continue;
        DFS(i, V);
    }
}

void BFS(int start, int V) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        printf("%d ", vertex);
        for(int i = 1; i <= V; i++) {
            if(visited[i] || Graph[vertex][i] == 0)
                continue;
            q.push(i);
            visited[i] = true;
        }
    }
    printf("\n");
}