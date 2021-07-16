#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    int n, max = 0;
    cin >> n;

    stack<int> number;
    string result;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        if(temp > max) {
            for(int j = max + 1; j <= temp; j++) {
                number.push(j);
                result.append("+\n");
            }
        }
        else {
            if(number.top() != temp) {
                result = "NO\n";
                break;
            }
        }
        number.pop();
        result.append("-\n");
        if(temp > max)
            max = temp;
    }

    cout << result;
    return 0;
}