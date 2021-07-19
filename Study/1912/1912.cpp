#include <cstdio>
#include <vector>

using namespace std;

int DP(int num);
int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    vector<int> A(num + 1, 0);
    vector<int> D(num + 1, 0);

    for(int i = 1; i <= num; i++) {
        scanf("%d", &A[i]);
    }

    int result = A[1];

    for(int i = 1; i <= num; i++) {
        D[i] = max(A[i], D[i - 1] + A[i]);
        result = max(result, D[i]);
    }

    return result;
}