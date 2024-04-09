#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int len = nums.size();
    map<int, int> pocketmon;

    for(int i = 0; i < len; i++) {
        if(pocketmon.count(nums[i])) pocketmon[nums[i]]++;

        pocketmon.insert(make_pair(nums[i], 1));
    }

    return len / 2 > pocketmon.size() ? pocketmon.size() : len / 2;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> pocketmon(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> pocketmon[i];
    }

    cout << solution(pocketmon) << endl;
    return 0;
}