#include <cstdio>
#include <vector>
#define MAX 10001

using namespace std;

int N, M;
int maximum, temp;

vector<int> computer[MAX];
int counter[MAX];

void DFS(int num, int start, int count);

int main(void) {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);

        computer[num2].push_back(num1);
    }

    for(int i = 1; i <= N; i++) {
        temp = 0;

        DFS(i, i, 1);
        counter[i] = temp;
        maximum = (counter[i] > maximum ? counter[i] : maximum);
    }

    for(int i = 1; i <= N; i++) {
        if(counter[i] == maximum)
            printf("%d ", i);
    }
    
    printf("\n");
    return 0;
}

void DFS(int num, int start, int count) {
    if(count != 1 && start == num) return;

    temp = (count > temp ? count : temp);
    int len = computer[num].size();

    for(int i = 0; i < len; i++) {
        int next = computer[num][i];
        DFS(next, start, count + 1);
    }
}