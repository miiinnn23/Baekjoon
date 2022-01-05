#include <iostream>
#include <string>
#include <list>
// 1406

using namespace std;

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;

        list<char> pwd;
        auto cursor = pwd.end();

        for(int j = 0; j < str.length(); j++) {
            switch(str[j]) {
                case '<':
                    if(cursor != pwd.begin()) {
                        cursor--;
                    }
                    break;
                case '>':
                    if(cursor != pwd.end()) {
                        cursor++;
                    }
                    break;
                case '-':
                    if(cursor != pwd.begin()) {
                        cursor = pwd.erase(--cursor);
                    }
                    break;
                default:
                    pwd.insert(cursor, str[j]);
                    break;
            }
        }

        for(auto it = pwd.begin(); it != pwd.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}