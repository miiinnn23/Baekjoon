#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;
vector<deque<int> > gear(4);

int solution(const vector<vector<int> >& command);

int main(void) {
    for(int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for(char c: s) {
            gear[i].push_back(c - '0');
        }
    }

    int K;
    cin >> K;
    vector<vector<int> > command(K, vector<int>(2));
    for(int i = 0; i < K; i++) {
        cin >> command[i][0] >> command[i][1];
    }
    cout << solution(command) << endl;

    return 0;
}

int solution(const vector<vector<int> >& command) {
    int score = 0;

    int length = command.size();
    for(int now = 0; now < length; now++) {
        int target = command[now][0];
        int dir = command[now][1];
        vector<int> rotation(4, 0);

        int temp_dir = dir;
        for(int i = target - 2; i >= 0; i--) {
            if(gear[i + 1][6] == gear[i][2]) break; // 두 극이 같으면 회전하지 않음 -> 한번 회전하지 않으면 그 왼쪽의 톱니바퀴도 회전하지 않음
            else if(gear[i + 1][6] != gear[i][2]) {
                temp_dir *= -1;
                rotation[i] = temp_dir;
            }
        }
        
        temp_dir = dir;
        for(int i = target; i < 4; i++) {
            if(gear[i - 1][2] == gear[i][6]) break; // 두 극이 같으면 회전하지 않음 -> 한번 회전하지 않으면 그 왼쪽의 톱니바퀴도 회전하지 않음
            else if(gear[i - 1][2] != gear[i][6]) {
                temp_dir *= -1;
                rotation[i] = temp_dir;
            }
        }

        rotation[target - 1] = dir;

        for(int i = 0; i < 4; i++) {
            if(rotation[i] == 0) continue;
            else if(rotation[i] == 1) {
                int temp = gear[i].back();
                gear[i].pop_back();
                gear[i].push_front(temp);
            }
            else {
                int temp = gear[i].front();
                gear[i].pop_front();
                gear[i].push_back(temp);
            }
        }

    }

    score += 1 * gear[0][0] + 2 * gear[1][0] + 4 * gear[2][0] + 8 * gear[3][0];
    return score;
}