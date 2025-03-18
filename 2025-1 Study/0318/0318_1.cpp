// https://velog.io/@zvyg1023/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-Level.2-%EC%96%91%EA%B6%81%EB%8C%80%ED%9A%8C-DFS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int _N, max_diff = -1;

int diff_calc(const vector<int>& ryan, const vector<int>& apeach) {
    int ryan_score = 0, apeach_score = 0;

    for(int i = 0; i < 11; i++) {
        if(ryan[i] != 0 || apeach[i] != 0) {
            if(ryan[i] > apeach[i]) ryan_score += (10 - i);
            else apeach_score += (10 - i);
        }
    }
    return ryan_score - apeach_score;
}

void DFS(int arrow, int node, vector<int> ryan, const vector<int>& apeach) {
    if(node == 11) { // 종료 조건
        if(arrow > 0) ryan[10] = arrow; // 남은 화살 전부 0점에 보관

        int diff = diff_calc(ryan, apeach);

        if(diff <= 0) return; // 라이언이 이길 수 없는 경우

        if(max_diff < diff) {
            answer.assign(ryan.begin(), ryan.end());
            max_diff = diff;
        }
        else if(max_diff == diff) {
            for(int i = 10; i >= 0; i--) {
                if(answer[i] < ryan[i]) {
                    // 새로운 조합이 기존보다 더 낮은 점수를 많이 쐈을 경우 바뀌어야됨
                    answer.assign(ryan.begin(), ryan.end());
                    break;
                }
                // 기존 조합이 새로운 조합보다 더 낮은 점수를 많이 쐈을 경우 바뀌면 안됨
                // (이거 안넣어주면 새로운 조합이 더 낮은 점수에서 많이 쏜 부분 발견할때까지 계속 검사함)
                else if(answer[i] > ryan[i]) break;
            }
        }
        return;
    }

    // 1. 라이언이 해당 점수에 어피치보다 한발 더 쐈을 경우
    if(arrow > apeach[node]) {  
        ryan[node] = apeach[node] + 1;
        DFS(arrow - (apeach[node] + 1), node + 1, ryan, apeach);
    }
    // 2. 라이언이 해당 점수에 한발도 안 쏠 경우
    ryan[node] = 0;
    DFS(arrow, node + 1, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    answer.push_back(-1);
    _N = n;

    vector<int> ryan(11, 0);

    DFS(n, 0, ryan, info);

    return answer;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> info(11, 0);

    for(int i = 0; i < 11; i++) {
        cin >> info[i];
    }

    vector<int> answer = solution(n, info);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ", ";
    }
    cout << endl;
    return 0;
}