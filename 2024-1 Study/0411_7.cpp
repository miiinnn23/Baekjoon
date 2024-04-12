#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    int n = citations.size();
    for(int i = 0; i < n; i++) {
        if(i + 1 <= citations[i]) answer++;
    }

    return answer;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> citations(n, 0);


    for(int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    cout << solution(citations) << endl;
    return 0;
}