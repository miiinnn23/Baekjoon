#include <iostream>
#include <string>
#include <cmath>

using namespace std;

char bonus[3] = { 'S', 'D', 'T' };
int score[3] = { 0 };

int solution(string dartResult) {
    int answer = 0;
    
    int len = dartResult.length();
    int index = -1;
    
    for(int i = 0; i < len; i++) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9') {
            index++;
            if(dartResult[i + 1] == '0') {
                score[index] = 10;
                i++;
            }
            else {
                score[index] = (int)(dartResult[i] - '0');
            }
        }
        
        else if(dartResult[i] == '*') {
            score[index] *= 2;
            if(index > 0) score[index - 1] *= 2;
        }
        
        else if(dartResult[i] == '#') score[index] *= -1;
        
        else {
            for(int j = 0; j < 3; j++) {
                if(dartResult[i] == bonus[j]) {
                    score[index] = (int)pow(score[index], j + 1);
                }
            }
        }
        cout << index << " " << score[index] << endl;
    }
    
    for(int i = 0; i < 3; i++) {
        // cout << score[i] << endl;
        answer += score[i];
    }
    return answer;
}

int main(void) {
    string s;
    cin >> s;
    cout << solution(s) << endl;
    return 0;
}