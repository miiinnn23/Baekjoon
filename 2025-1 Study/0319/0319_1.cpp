// 2024-1 Study/0411_3.cpp
// 코드 복습
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int solution(int N, int num) {
    if(N == num) return 1;

    vector<vector<int> > dp(9, vector<int>()); // N의 사용 횟수로 만들 수 있는 숫자 저장
    
    dp[0].push_back(0); // dp[0] = 0
    dp[1].push_back(N); // dp[1] = 1(N 1개로 만들 수 있는 숫자는 N 하나)

    for(int i = 2; i <= 8; i++) {
        // NN, NNN, NNNN, ... 등과 같은 숫자 저장
        int mult = 0, sum = 0;
        while(mult != i) {
            sum += (int)pow(10, mult++) * N;
        }
        dp[i].push_back(sum);

        for(int j = 1; j < i; j++) {
            for(int k = 0; k < dp[j].size(); k++) {
                for(int l = 0; l < dp[i - j].size(); l++) {
                    if(dp[i - j][l] == 0) continue; // 나눠주는 수가 0인 경우 제외
                    dp[i].push_back(dp[j][k] + dp[i - j][l]); // i개를 써서 연산할 수 있는 모든 경우의 수 저장
                    dp[i].push_back(dp[j][k] - dp[i - j][l]); // (중복, 0, 음수 포함)
                    dp[i].push_back(dp[j][k] * dp[i - j][l]);
                    dp[i].push_back(dp[j][k] / dp[i - j][l]);
                }
            }
        }

        for(int j = 0; j < dp[i].size(); j++) { // 연산 결과 돌면서 num과 같은 경우 결과 반환
            if(dp[i][j] == num) return i;
        }
    }
    return -1;
}

int main(void) {
    int N, num;
    cin >> N >> num;

    cout << solution(N, num) << endl;
    return 0;
}