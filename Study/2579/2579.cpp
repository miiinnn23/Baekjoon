#include <cstdio>
#include <vector>

using namespace std;

int DP(int num);
int max(int num1, int num2) { return num1 > num2 ? num1 : num2; }

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}

int DP(int num) {
    vector<int> stair(num + 1, 0);
    vector<int> score(num + 1, 0);

    for(int i = 1; i <= num; i++) {
        scanf("%d", &stair[i]);
    }

    if(num >= 1) score[1] = stair[1];
    if(num >= 2) score[2] = stair[1] + stair[2];
    
    for(int i = 3; i <= num; i++) {
        score[i] = max(score[i - 2] + stair[i], score[i - 3] + stair[i - 1] + stair[i]);
    }

    return score[num];
}