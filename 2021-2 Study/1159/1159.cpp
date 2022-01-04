#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int alphabet[26] = { 0 };
    string result;
    int player;

    cin >> player;

    for(int i = 0; i < player; i++) {
        string name;
        cin >> name;
        alphabet[name[0] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(alphabet[i] >= 5) {
            result += (i + 'a');
        }
    }

    if(result.length() > 0) cout << result << "\n";
    else cout << "PREDAJA\n";
    return 0;
}