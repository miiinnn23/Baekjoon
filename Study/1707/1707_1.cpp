#include <cstdio>
#include <vector>
#define MAX 20001

using namespace std;

vector<int> graph[MAX];
vector<int> visited(MAX, 0);

void DFS(int vertex);
bool isBG(int v);

int main(void) {
    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; i++) {
        int v, e;
        scanf("%d %d", &v, &e);

        for(int j = 0; j < e; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int j = 1; j <= v; j++) {
            if(visited[j] == 0) {
                DFS(j);
            }
        }
        bool result = isBG(v);

        if(result) printf("YES\n");
        else printf("NO\n");

        for(int j = 0; j <= v; j++) { // 초기화
            graph[j].clear();
            visited[j] = 0;
        }
    }
    return 0;
}

void DFS(int vertex) {
    if(visited[vertex] == 0)
        visited[vertex] = 1;

    for(int i = 0; i < graph[vertex].size(); i++) {
        int next = graph[vertex][i];
        if(visited[next] == 0) {
            if(visited[vertex] == 1)
                visited[next] = 2;
            else if(visited[vertex] == 2)
                visited[next] = 1;
            DFS(next);
        }
    }
}

bool isBG(int v) {
    for(int i = 1; i <= v; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];
            if(visited[i] == visited[next])
                return false;
        }
    }
    return true;
}