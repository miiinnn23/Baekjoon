#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i : scoville) {
        pq.push(i);
    }

    int count = 0, index = 0;
    while(true) {
        if(pq.top() < K) {
            int temp = pq.top();
            pq.pop();
            if(pq.empty()) return -1;
            
            pq.push((long)(temp + pq.top() * 2));
            pq.pop();
            count++;
        }
        else {
            pq.pop();
            if(pq.empty()) break;
        }
    }

    return count;
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