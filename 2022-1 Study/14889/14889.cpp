#include <cstdio>
#include <cmath>
#include <climits>
#define MAX 21

int N;
int result = INT_MAX;

int graph[MAX][MAX];
bool visited[MAX];
void DFS(int num, int count);

int main(void) {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    DFS(0, 0);
    printf("%d\n", result);
    return 0;
}

void DFS(int num, int count) {
    if(count == N / 2) {
        int start = 0, link = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i] && visited[j]) start += graph[i][j];
                if(!visited[i] && !visited[j]) link += graph[i][j];
            }
        }

        int sub = abs(start - link);
        if(result > sub) result = sub;
        return;
    }
    for(int i = num; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            DFS(i + 1, count + 1);
            visited[i] = false;
        }
    }
}