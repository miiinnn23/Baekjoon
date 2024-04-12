#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    vector<int> step = { 781, 156, 31, 6, 1 };
    map<char, int> pair = { make_pair('A', 0), make_pair('E', 1), make_pair('I', 2), make_pair('O', 3), make_pair('U', 4) };

    int count = 0;
    int len = word.length();
    for(int i = 0; i < len; i++) {
        count += pair[word[i]] * step[i] + 1;
    }
    return count;
}

int main(void) {
    string word;
    cin >> word;

    cout << solution(word) << endl;
    return 0;
}