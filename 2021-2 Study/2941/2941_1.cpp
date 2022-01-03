#include <iostream>
#include <string>
// 문자열 치환 방식
using namespace std;

int main(void) {
    string word;
    cin >> word;

    string alphabet[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    
    for(int i = 0; i < 8; i++) {
        while(true) {
            int index = word.find(alphabet[i]);
            if(index == string::npos) break; // 더이상 찾을 수 없을 경우 loop 종료
            word.replace(index, alphabet[i].length(), "."); // index부터 alphabet의 길이만큼까지 .으로 치환
        }
    }

    cout << word.length() << "\n";    
    return 0;
}