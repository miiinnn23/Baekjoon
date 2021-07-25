#include <cstdio>
#define MAX 1001

int graph[MAX];
bool visited[MAX];
void DFS(int vertex);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[j]);
        }

        int count = 0;
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                DFS(j);
                count++;
            }
        }

        printf("%d\n", count);
        for(int j = 1; j <= n; j++) {
            graph[j] = 0;
            visited[j] = false;
        }
        
    }
    return 0;
}

void DFS(int vertex) {
    visited[vertex] = true;

    if(visited[graph[vertex]]) return;
    else DFS(graph[vertex]);
}