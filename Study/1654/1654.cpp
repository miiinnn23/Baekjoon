#include <cstdio>

int main(void) {
    int k, n;
    long long len[10001] = { 0 };

    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; i++) {
        scanf("%lld", &len[i]);
    }

    long long left = 0;
    long long right;
    long long result = 0;

    for(int i = 0; i < k; i++) {
        right = (right > len[i] ? right : len[i]);  // 최댓값
    }
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for(int i = 0; i < k; i++) {
            sum += len[i] / mid;
        }

        if(sum >= n) {
            left = mid + 1;
            result = (result > mid ? result : mid);
        }
        else right = mid - 1;
    }

    printf("%lld\n", result);
    return 0;
}