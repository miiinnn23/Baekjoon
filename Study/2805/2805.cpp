#include <cstdio>

int main(void) {
    long long N, M;
    long long tree[1000001];
    scanf("%lld %lld", &N, &M);

    for(int i = 0; i < N; i++) {
        scanf("%lld", &tree[i]);
    }

    long long left = 0;
    long long right;
    for(int i = 0; i < N; i++) {
        right = (right > tree[i] ? right : tree[i]);
    }
    long long result = 0;


    while(left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            sum += (tree[i] - mid > 0 ? tree[i] - mid : 0);
        }

        if(sum >= M) {
            left = mid + 1;
            result = (result > mid ? result : mid);
        }
        else right = mid - 1;
    }

    printf("%lld\n", result);
    
    return 0;
}