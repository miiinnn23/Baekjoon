#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void search(vector<int> numbers, int node, int sum, int target, int mode) {
    if(mode)
        sum += numbers[node++];
    else
        sum -= numbers[node++];

    if(node == numbers.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    search(numbers, node, sum, target, 0);
    search(numbers, node, sum, target, 1);
}

int solution(vector<int> numbers, int target) {
    search(numbers, 0, 0, target, 0);
    search(numbers, 0, 0, target, 1);
    return cnt;
}

int main(void) {
    int N, target;
    cin >> N;
    
    vector<int> numbers(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    cin >> target;

    cout << solution(numbers, target) << endl;
    return 0;
}