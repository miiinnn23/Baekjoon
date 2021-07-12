#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return (a.first < b.first);
}

int main(void) {
    int n;
    scanf("%d", &n);
    vector<pair<int, string> > list(n);

    for(int i = 0; i < n; i++) {
        cin >> list[i].first >> list[i].second;
    }

    stable_sort(list.begin(), list.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << list[i].first << " " << list[i].second << "\n";
    }
    return 0;
}