#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main(void) {
    int N, C;
    scanf("%d %d", &N, &C);
    vector<int> distance;

    for(int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        distance.push_back(temp);
    }

    sort(distance.begin(), distance.end());

    int left = 1;
    int right = distance.back() - distance.front();
    int result = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        int wifi = 1, before = 0;
        
        for(int i = 1; i < N; i++) {
            if((distance[i] - distance[before]) >= mid) {
                before = i;
                wifi++;
            }
        }

        if(wifi >= C) {
            left = mid + 1;
            result = (result > mid ? result : mid);
        }
        else right = mid - 1;
    }

    printf("%d\n", result);
    return 0;
}