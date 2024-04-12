#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        sum[y][x] = -1;
    }

    sum[1][1] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) continue;

            if(sum[i][j] == -1) {
                sum[i][j] = 0;
                continue;
            }

            sum[i][j] = (sum[i - 1][j] + sum[i][j - 1]) % MOD;
        }
    }

    return sum[n][m] % MOD;
}

int main(void) {
    int m, n;
    vector<vector<int>> puddles;

    cin >> m >> n;

    int puddle;
    cin >> puddle;

    for(int i = 0; i < puddle; i++) {
        int x, y;
        cin >> x >> y;
        puddles.push_back({x, y});
    }

    cout << solution(m, n, puddles) << endl;

    return 0;
}