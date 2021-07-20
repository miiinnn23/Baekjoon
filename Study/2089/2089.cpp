#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void) {
    long long n, temp;
    scanf("%lld", &n);
    string result;

    if(n == 0) result = "0";
    else {
        temp = n;
        while(temp != 1) {
            if(abs(temp) % 2 == 1) {
                temp--;
                temp /= (-2);
                result.insert(result.begin(), '1');
            }
            else {
                temp /= (-2);
                result.insert(result.begin(), '0');
            }
        }
        result.insert(result.begin(), '1');
    }

    cout << result << "\n";
    return 0;
}