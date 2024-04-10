#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    int count = 0;

    stack<char> test;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            test.push(s[i]);
        }
        else {
            if(test.empty()) {
                return false;
            }
            else test.pop();
        }
    }

    return test.empty();
}

int main(void) {
    string s;
    cin >> s;

    cout << solution(s) << endl;
    return 0;
}