#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> pq;
    queue<pair<int, int> > q;

    int len = priorities.size();
    for(int i = 0; i < len; i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    int count = 1;
    while(true) {
        pair<int, int> temp = q.front();
        q.pop();

        if(temp.second != pq.top())
            q.push(temp);
        else
            if(temp.first == location) {
                answer = count;
                break;
            }
            else {
                count++;
                pq.pop();
            }
    }
    return answer;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> propterties(N, 0);
    int location;
    for(int i = 0; i < N; i++) {
        cin >> propterties[i];
    }
    cin >> location;

    cout << solution(propterties, location) << endl;
    return 0;
}