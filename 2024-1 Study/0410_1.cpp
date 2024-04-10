#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int len = number.length();

    
    while(k >= 0) {
        // int limit = len - k;
        int cursor = 0;
        char temp = number[cursor];

        if(k > 1) {
            for(int i = 0; i < k; i++) {
                if(temp < number[i]) {
                    temp = number[i];
                    cursor = i;
                }
            }
            answer += temp;
            number.erase(0, cursor + 1);
            cout << number << endl;
            k--;
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