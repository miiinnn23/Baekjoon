#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    vector<int> time;

    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        time.push_back(num);
    }

    sort(time.begin(), time.end());

    int sum = 0, total = 0;
    for(int i = 0; i < N; i++) {
        total += time[i];
        sum += total;
    }

    printf("%d\n", sum);
    return 0;
}