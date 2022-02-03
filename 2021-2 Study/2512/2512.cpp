#include <cstdio>
#define MAX 100001

int money[MAX];

int main(void) {
    int N, M;
    scanf("%d", &N);
    
    int maximum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &money[i]);
        if(maximum < money[i]) maximum = money[i];
    }

    scanf("%d", &M);

    int left = 0;
    int right = maximum;
    int result = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += (money[i] > mid ? mid : money[i]);
        }

        if(sum <= M) {
            left = mid + 1;
            result = (result > mid ? result : mid);
        }
        else
            right = mid - 1;
    }

    printf("%d\n", result);
    return 0;
}