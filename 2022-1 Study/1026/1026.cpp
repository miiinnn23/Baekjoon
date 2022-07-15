#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int i, int j) {
    return j < i;
}

int main(void) {
    vector<int> A;
    vector<int> B;

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        A.push_back(num);
    }

    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        B.push_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i] * B[i];
    }

    printf("%d\n", sum);
    return 0;
}