#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    vector<string> suffix(s.length());
    for(int i = 0; i < s.length(); i++) {
        suffix[i] = s.substr(i, (s.length() - i));
    }

    sort(suffix.begin(), suffix.end());
    for(int i = 0; i < suffix.size(); i++) {
        cout << suffix[i] << "\n";
    }
    return 0;
}