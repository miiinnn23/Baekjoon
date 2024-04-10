#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    map<string, int> info;

    for(auto& i : clothes) {
        if(info.count(i[1])) info[i[1]]++;
        info.insert(make_pair(i[1], 1));
    }

    int len = info.size();
    for(auto& i : info) {
        answer *= (i.second + 1);
    }
    
    return answer - 1;
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<string> > clothes;
    for(int i = 0; i < N; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        clothes.push_back({temp1, temp2});
    }

    cout << solution(clothes) << endl;

    return 0;
}