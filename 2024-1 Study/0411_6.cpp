#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool right(string p) {
    stack<char> b;

    int len = p.length();
    for(int i = 0; i < len; i++) {
        if(p[i] == '(') b.push('(');
        else {
            if(b.empty()) return false;
            b.pop();
        }
    }
    return b.empty();
}

string rev(string p) {
    int len = p.length();
    string temp = "";
    for(int i = 1; i < len - 1; i++) {
        temp += p[i] == '(' ? ")" : "(";
    }
    return temp;
}

string solution(string p) {
    string answer = "";

    if(p.length() < 1) return "";   // 1

    int len = p.length();
    string u, v;
    
    int count = p[0] == '(' ? -1 : 1;

    for(int i = 1; i < len; i++) {  // 2
        if(p[i] == '(') count--;
        else count++;
        
        if(count == 0) {
            u = p.substr(0, i + 1);
            if(i == len - 1) v = "";
            else v = p.substr(i + 1, len - 1);
            break;
        }
    }

    if(right(u)) {                  // 3
        answer += u + solution(v);  // 3-1
    }
    else {                          // 4
        string temp = "(" + solution(v) + ")"; // 4-1 ~ 4-3
        temp += rev(u);             // 4-4
        answer += temp;             // 4-5
    }

    return answer;
}

int main(void) {
    string w;
    cin >> w;

    cout << solution(w) << endl;
    return 0;
}