#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define MAX 5001

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // vector<int> DP(n + 1, 1);
    long DP[MAX];
    DP[0] = 1;
    DP[2] = 3;
    
    if(n % 2 == 1) return 0;
    
    for(int i = 4; i <= n; i += 2) {
        DP[i] = 3 * DP[i - 2];
        for(int j = i - 4; j >= 0; j -= 2) {
            DP[i] += 2 * DP[j];
        }
        DP[i] %= MOD;
    }
    
    return (int)DP[n];
}

int main(void) {
    int n;
    cin >> n;
    cout << solution(n) << endl;
    return 0;
}