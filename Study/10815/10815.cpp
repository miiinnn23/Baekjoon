#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;
    vector<int> card;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        card.push_back(temp);
    }

    sort(card.begin(), card.end());

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);

        int left = 0;
        int right = N - 1;
        bool flag = false;

        while(left <= right) {
            int mid = (left + right) / 2;
            
            if(temp > card[mid]) left = mid + 1;
            else if(temp == card[mid]) {
                flag = true;
                break;
            }
            else right = mid - 1;     
        }

        if(flag) printf("1 ");
        else printf("0 ");
        
    }
    printf("\n");
    return 0;
}