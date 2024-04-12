#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1]) return v1[0] < v2[0];
    else return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);

    int len = routes.size();
    int ind = 0;
    while(ind < len) {
        int next = ind + 1;
        while(next < len && routes[ind][1] >= routes[next][0]) next++;

        ind = next;
        answer++;
    }
    return answer;
}

int main(void) {
    int cars;
    cin >> cars;

    vector<vector<int>> routes(cars, vector<int>(2, 0));
    for(int i = 0; i < cars; i++) {
        cin >> routes[i][0] >> routes[i][1];
    }

    cout << solution(routes) << endl;
    return 0;
}