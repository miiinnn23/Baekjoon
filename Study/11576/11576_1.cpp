#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int A, B;
    int m;

    cin >> A >> B;
    cin >> m;

    vector<int> num(m);
    for (int i = 0; i < m; i++)
        cin >> num[i];

    int dec = 0;
    for (int i = 0; i < m; i++)
        dec += num[i] * pow(A, m - 1 - i);

    vector<int> result;

    int n = dec;
    while(n != 0)
    {
        result.push_back(n % B);
        n /= B;
    }

    for(int i = result.size() - 1; i >= 0; i--){
        if(i == 0)
            cout << result[i] << "\n";
        else
            cout << result[i] << ' ';       
    }
}