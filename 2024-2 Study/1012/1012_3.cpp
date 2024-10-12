#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

bool Compare(int &a, int &b) { return a > b; }
int main(void) {
    cin >> N;
    vector<int> per;
    for(int i = 1; i <= N; i++) {
        per.push_back(i);
    }

    for(int i = 0; i < per.size(); i++) {
        cout << per[i] << " ";
    }
    cout << endl;
    while(next_permutation(per.begin(), per.end())) {
        for(int i = 0; i < per.size(); i++) {
            cout << per[i] << " ";
        }
        cout << endl;
    }

    sort(per.begin(), per.end(), Compare);

    for(int i = 0; i < per.size(); i++) {
        cout << per[i] << " ";
    }
    cout << endl;

    // vector<int> temp = { 1, 1, 0, 0 };

    // do {
    //     for(int i = 0; i < per.size(); i++) {
    //         if(temp[i]==1)
    //             cout << per[i] << ' ';
    //     }
    //     cout << endl;
    // } while(prev_permutation(temp.begin(), temp.end()));

    do {
        for(int i = 0; i < per.size(); i++) {
            cout << per[i] << ' ';
        }
        cout << endl;
    } while(prev_permutation(per.begin(), per.end()));
    return 0;
}