#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 26

using namespace std;

int graph[MAX][MAX];

void DFS(int a, int b);
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, c;
vector<int> sorting;

int main(void) {
    scanf("%d", &n);

    string temp;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        for(int j = 1; j <= n; j++) {
            graph[i][j] = (temp[j - 1] - '0');
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == 1) {
                c = 0;
                DFS(i, j);
                sorting.push_back(c);
            }
        }
    }
    
    sort(sorting.begin(), sorting.end());
    printf("%lu\n", sorting.size());
    for(int i = 0; i < sorting.size(); i++) {
        printf("%d\n", sorting[i]);
    }

    return 0;
}

void DFS(int a, int b) {
    graph[a][b] = 0;
    c++;

    for(int i = 0; i < 4; i++) {
        if((a + dy[i] < 1) || (a + dy[i] > n) || (b + dx[i] < 1) || (b + dx[i] > n))
            continue;
            
        if(graph[a + dy[i]][b + dx[i]] == 1)
            DFS(a + dy[i], b + dx[i]);
    }
}