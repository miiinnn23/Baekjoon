#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    
    return answer;
}

int main(void) {
    int N, K;
    cin >> N;

    vector<int> scoville(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> scoville[i];
    }
    cin >> K;

    cout << solution(scoville, K) << endl;

    return 0;
}