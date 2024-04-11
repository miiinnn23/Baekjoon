#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int len = people.size();
    sort(people.begin(), people.end());

    int front = 0, back = len - 1;

    while(front <= back) {
        if(people[back] + people[front] <= limit) front++;
        
        back--;
        answer++;
    }

    return answer;
}

int main(void) {
    int N, limit;
    cin >> N;

    vector<int> people(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> people[i];
    }
    cin >> limit;

    cout << solution(people, limit) << endl;
    return 0;
}