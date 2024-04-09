#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > answer;
void Hanoi(int n, int a, int b, int c) {
    if(n == 1) {
        vector<int> temp(2, 0);
        temp[0] = a;
        temp[1] = c;
        answer.push_back(temp);
        return;
    }
    else {
        Hanoi(n - 1, a, c, b);
        vector<int> temp(2, 0);
        temp[0] = a;
        temp[1] = c;
        answer.push_back(temp);
        Hanoi(n - 1, b, a, c);
    }
}

vector<vector<int> > solution(int n) {
    Hanoi(n, 1, 2, 3);

    return answer;
}

int main(void) {
    int n;
    cin >> n;

    solution(n);
    
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i][0] << ' ' << answer[i][1] << endl;
    }
    return 0;
}