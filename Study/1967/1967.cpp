#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 10001

using namespace std;

int n;
vector<pair<int, int> > tree[MAX]; // 노드, 가중치
bool visited[MAX];
int diameter, furthest;

void DFS(int vertex, int dist);

int main(void) {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        tree[a].push_back(pair<int, int>(b, c));
        tree[b].push_back(pair<int, int>(a, c));
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
    for(int i = 0; i < tree[vertex].size(); i++) {
        DFS(tree[vertex][i].first, dist + tree[vertex][i].second);
    }
}