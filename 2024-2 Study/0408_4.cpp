#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int len = progresses.size();
    vector<int> temp(len, 0);

    for(int i = 0; i < len; i++) {
        int left = 100 - progresses[i];
        temp[i] = left % speeds[i] == 0 ? left / speeds[i] : left / speeds[i] + 1;
    }
    
    int day = 1, max = temp[0];
    for(int i = 1; i < len; i++) {
        if(temp[i] <= max) {
            day++;
            continue;
        }
        // if(temp[i] >= temp[i + 1]) {
        //     day++;
        //     continue;
        // }
        else {
            answer.push_back(day);
            day = 1;
            max = temp[i];
        }
    }

    answer.push_back(day);
    return answer;
}

int main(void) {
    vector<int> progresses, speeds;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        progresses.push_back(temp);
    }

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        speeds.push_back(temp);
    }

    vector<int> answer = solution(progresses, speeds);
    for(auto& i : answer) {
        cout << i << endl;
    }
    return 0;
}