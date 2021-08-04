#include <cstdio>
#include <vector>
#define MAX 100001

using namespace std;

vector<int> tree[MAX];
int parent[MAX];
bool visited[MAX] = { false };

int n;
void DFS(int node);

int main(void) {
    scanf("%d", &n);

    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);
    for(int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}

void DFS(int node) {
    visited[node] = true;

    for(int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        
        if(!visited[next]) {
            parent[next] = node;
            DFS(next);
        }
    }
}