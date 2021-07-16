#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(void) {
    long n;
    int b;
    scanf("%ld %d", &n, &b);

    string result;
    while(true) {
        long temp = n % b;
        if(temp >= 10) {
            result.insert(result.begin(), temp - 10 + 'A');
        }
        else {
            result.insert(result.begin(), (temp + '0'));
        }
        n /= b;
        if(n == 0) break;
    }

    cout << result << "\n";
    return 0;
}