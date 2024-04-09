#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    int len = phone_book.size();
    
    for(int i = 0; i < len - 1; i++) {
        if(phone_book[i + 1].find(phone_book[i]) == 0)
            return false;
    }
    // for(auto& i : phone_book) {
    //     for(auto& j : phone_book) {
    //         if(i == j) continue;
    //         if(i.length() > j.length()) continue;
            
    //         if(j.find(i) == 0)
    //             return false;
    //     }
    // }

    return answer;
}

int main(void) {
    int N;
    cin >> N;
    
    vector<string> phone_book;
    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        phone_book.push_back(temp);
    }

    cout << solution(phone_book) << endl;
    return 0;
}