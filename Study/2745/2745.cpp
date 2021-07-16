#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main(void) {
    string n;
    int b;
    cin >> n >> b;

    int length = n.size(), power = n.size();
    long result = 0;
    for(int i = 0; i < length; i++) {
        if(n[i] >= 'A' && n[i] <= 'Z') {
            result += (n[i] - 'A' + 10) * (int)(pow(b, power - 1));
        }
        else {
            result += (n[i] - '0') * (int)(pow(b, power - 1));
        }
        power--;
    }

    cout << result << "\n";
    return 0;
}