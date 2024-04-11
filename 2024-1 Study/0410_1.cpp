#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int len = number.length();
    
    for(int j = 0; j < len; j++) {
        if(answer.length() >= (len - k)) break;
        
        int cursor = 0;
        char temp = number[cursor];

        for(int i = 0; i <= k; i++) {
            if(temp < number[i]) {
                temp = number[i];
                cursor = i;
            }
        }
        answer += temp;
        number.erase(0, cursor + 1);

        k -= cursor;

        if(k <= 0) {
            answer += number;
            break;
        }
    }
    
    return answer;
}

int main(void) {
    string num;
    cin >> num;
    int k;
    cin >> k;
    
    cout << solution(num, k) << endl;
    return 0;
}