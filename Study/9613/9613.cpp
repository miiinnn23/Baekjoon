#include <cstdio>
#include <vector>

using namespace std;

int GCD(int a, int b);

int main(void) {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        vector<int> num(n);
        for(int j = 0; j < n; j++) {
            scanf("%d", &num[j]);
        }

        long long sum = 0;
        for(int j = 0; j < n; j++) {
            for(int k = (n - 1); k > j; k--) {
                sum += GCD(num[j], num[k]);
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}

int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}