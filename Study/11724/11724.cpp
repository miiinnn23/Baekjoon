#include <cstdio>
#define MAX 1001

using namespace std;

int graph[MAX][MAX] = { 0 };
bool visited[MAX] = { false };

void DFS(int vertex, int V, int& C);

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }

    int c = 0, count = 0, i = 1;
    while(c != n) {
        int temp = c;
        DFS(i, n, c);
        if(temp < c)
            count++;

        i++;
    }
    printf("%d\n", count);
    return 0;
}

void DFS(int vertex, int V, int& c) {
    if(!visited[vertex]){
        visited[vertex] = true;
        c++;
    }
    for(int i = 1; i <= V; i++) {
        if(visited[i] || graph[vertex][i] == 0)
            continue;
        DFS(i, V, c);
    }
}