#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string n;
    cin >> n;

    string result;
    int temp = n[0] - '0';
    if(temp == 0) { // 0 생각 안해주면 틀림
        result += '0';
    }

    while(temp != 0) {
        if(temp % 2 == 1) 
            result.insert(result.begin(), '1');

        else 
            result.insert(result.begin(), '0');
        
        temp /= 2;
        if(temp == 0) break;
    }
    int len = result.size();

    for(int i = 1; i < n.size(); i++) {
        temp = n[i] - '0';
        for(int j = 0; j < 3; j++) {
            if(temp % 2 == 1)
                result.insert(result.begin() + len + (i - 1) * 3, '1');
            else 
                result.insert(result.begin() + len + (i - 1) * 3, '0');
            temp /= 2;
        }
    }

    cout << result << "\n";
    return 0;
}