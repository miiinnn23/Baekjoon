#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int answer = 0;
string dic = "AEIOU";

void DFS(string word, string target) {
    cnt++;

    if(word == target) {
        answer = cnt;
        return;
    }

    if(word.length() >= 5) return;

    for(int i = 0; i < 5; i++) {
        DFS(word + dic[i], target);
    }
}

int solution(string word) {
    DFS("", word);

    return answer - 1;
}

int main(void) {
    string word;
    cin >> word;

    cout << solution(word) << endl;
    return 0;
}