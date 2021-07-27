#include <cstdio>
#define MAX 100001

int student[MAX];
bool visited[MAX], checked[MAX];
void DFS(int vertex, int n, int& count);
// https://data-make.tistory.com/442
int main(void) {
    int t;
    scanf("%d", &t);
    
    while(t > 0) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &student[i]);
        }

        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(!visited[i])
                DFS(i, n, count);
        }

        printf("%d\n", n - count);
        for(int i = 1; i <= n; i++) {
            student[i] = 0;
            visited[i] = false;
            checked[i] = false;
        }
        t--;
    }
    return 0;
}

void DFS(int vertex, int n, int& count) {
    visited[vertex] = true;

    int next = student[vertex];
    if(!visited[next]) DFS(next, n, count);
    else if(!checked[next]) {
        int temp = next;
        while(temp != vertex) {
            count++;
            temp = student[temp];
        }
        count++;
    }
    checked[vertex] = true;
}