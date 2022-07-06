#include <cstdio>
#include <vector>
#define MAX 1000001

using namespace std;

void DP(int num);
void DFS(int num);

int graph[MAX];
bool visited[MAX];

int main(void) {
    int N;
    scanf("%d", &N);

    DP(N);
    printf("\n");
    return 0;
}

void DP(int num) {
    int result[MAX];

    result[1] = 0;
    result[2] = 1;
    result[3] = 1;

    graph[1] = 1;
    graph[2] = 1;
    graph[3] = 1;

    for(int i = 4; i <= num; i++) {
        graph[i] = i - 1;
        result[i] = result[i - 1] + 1;

        if(i % 3 == 0) {
            if(result[i / 3] < result[i]) {
                graph[i] = i / 3;
                result[i] = result[i / 3] + 1;
            }
        }
        if(i % 2 == 0) {
            if(result[i / 2] < result[i]) {
                graph[i] = i / 2;
                result[i] = result[i / 2] + 1;
            }
        }
    }
    
    printf("%d\n", result[num]);
    DFS(num);
}

void DFS(int num) {
    visited[num] = true;
    printf("%d ", num);

    if(num == 1) return;
    
    int next = graph[num];
    if(!visited[next])
        DFS(next);
}