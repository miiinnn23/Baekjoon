#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    vector<int> arr(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr.begin(), arr.end());

    printf("%d\n", arr[0] * arr[N - 1]);
    return 0;
}