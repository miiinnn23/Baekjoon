#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    int answer = 0;

    vector<vector<int>> dp;
    dp.push_back({ 0 });
    dp.push_back({ N });

    for(int i = 2; i <= 8; i++) {
        vector<int> temp;

        int k = 0, calc = 0;
        while(k != i) {
            calc += N * (int)pow(10, k++);
        }
        temp.push_back(calc);

        for(int j = 1; j < i; j++) {
            for(int l = 0; l < dp[j].size(); l++) {
                for(int m = 0; m < dp[i - j].size(); m++) {
                    if(dp[i - j][m] == 0) continue;
                    temp.push_back(dp[j][l] + dp[i - j][m]);
                    temp.push_back(dp[j][l] - dp[i - j][m]);
                    temp.push_back(dp[j][l] * dp[i - j][m]);
                    temp.push_back(dp[j][l] / dp[i - j][m]);
                }
            }
        }

        for(int j = 0; j < temp.size(); j++) {
            if(temp[j] == number) return i;
        }

        dp.push_back(temp);
        cout << temp.size() << endl;
    }

    return -1;
}

int main(void) {
    int N, number;
    cin >> N >> number;

    cout << solution(N, number) << endl;
    return 0;
}