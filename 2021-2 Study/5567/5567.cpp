#include <cstdio>
#include <queue>
#define MAX 501

using namespace std;

int friends[MAX][MAX] = { 0 };
bool visited[MAX] = { false };
int depth[MAX] = { 0 };

int count = 0;
int n, m;
void BFS(int num);

int main(void) {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        friends[a][b] = friends[b][a] = 1;
    }

    BFS(1);
    printf("%d\n", count);
    return 0;
}

void BFS(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = true;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        
        for(int i = 1; i <= n; i++) {
            if(visited[i] || friends[vertex][i] == 0)
                continue;
            q.push(i);
            visited[i] = true;
            depth[i] = depth[vertex] + 1;
            if(depth[i] > 2) return;

            count++;
        }
    }
}