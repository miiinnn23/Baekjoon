#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> bench;

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        bench.push_back(temp);
    }
    
    long long sum = 0;
    long long max = 0;
    for(int i = 0; i < N; i++) {
        if(max < bench[i]) max = bench[i];
        sum += bench[i];
    }
    
    long long K_max = max + M;
    long long K_min = (M + sum) % N == 0 ? (M + sum) / N : ((M + sum) / N) + 1;

    // 모든 사람이 한 벤치에 앉아 있는 경우 고려
    K_min = max > K_min ? max : K_min;
    cout << K_min << " " << K_max << "\n";
	return 0;
}