#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b) {
    return a > b ? b : a;
}

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len - 1;

    for(int i = 0; i < len; i++) {
        answer += (name[i] - 'A' <= 13 ? name[i] - 'A' : 26 - (name[i] - 'A'));
        int cursor = i + 1;

        while(cursor < len && name[cursor] == 'A') cursor++;

        move = min(move, i + len - cursor + min(i, len - cursor));
    }

    return answer + move;
}

int main(void) {
    string name;
    cin >> name;

    cout << solution(name) << endl;
    return 0;
}