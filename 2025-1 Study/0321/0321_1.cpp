#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int solution(string s) {
    int answer = s.size();

    for(int i = 1; i < s.size() / 2 + 1; i++) {
        string compressed = "";
        string pattern = s.substr(0, i);
        
        int repeat = 1; // 반복횟수 count
        for(int j = i; j < s.size(); j += i) {
            if(pattern == s.substr(j, i)) repeat++;
            else { // 이전패턴과 비교해서 달라졌을 경우, 이전까지 압축된 문자열 저장 후 다음 패턴 탐색
                compressed += ((repeat > 1) ? to_string(repeat) : "") + pattern;
                pattern = s.substr(j, i);
                repeat = 1;
            }
        }
        compressed += ((repeat > 1) ? to_string(repeat) : "") + pattern;
        answer = min(answer, compressed.size());
    }
    return answer;
}
 
int main(void) {
    string s;
    cin >> s;

    cout << solution(s) << endl;
    return 0;
}