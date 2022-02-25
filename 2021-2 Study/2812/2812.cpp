#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        scanf("%1d", &arr[i]);
    }

    deque<int> q;

    for(int i = 0; i < arr.size(); i++) {
        while(K && !q.empty() && q.back() < arr[i]) {
            q.pop_back();
            K--;
        }
        q.push_back(arr[i]);
    }

    for(int i = 0; i < q.size(); i++) {
        printf("%d", q[i]);
    }
    printf("\n");
    return 0;
}