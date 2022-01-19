#include <cstdio>
#include <vector>

using namespace std;

vector<int> array;
int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    array.resize(N + 1);
    for(int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        array[i + 1] = array[i] + temp;
    }

    for(int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        printf("%d\n", array[end] - array[start - 1]);
    }
    return 0;
}