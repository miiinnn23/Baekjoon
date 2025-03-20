#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define MAX 5001

using namespace std;

int solution(int N) {
    vector<long> DP(N + 1, 0);

    DP[0] = 1;
    DP[2] = 3;

    if(N % 2 != 0) return 0;

    for(int i = 4; i <= N; i += 2) {
        // 가로 너비가 2인 블록 배치하는 경우의 수 3가지
        DP[i] += 3 * DP[i - 2];
        // 가로 너비가 4 이상인 블록 배치하는 경우의 수 2가지(4, 6, 8, .. 등등 방법 2가지씩 존재)
        for(int j = i - 4; j >= 0; j -= 2) {
            DP[i] += 2 * DP[j];
        }
        DP[i] %= MOD;
    }
    return DP[N];
}

int main(void) {
    int N;
    cin >> N;

    cout << solution(N) << endl;
    return 0;
}