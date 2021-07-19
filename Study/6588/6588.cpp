#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    vector<int> prime(1000001, 0);
    prime[0] = prime[1] = -1;
    for(int i = 2; i * i <= 1000000; i++) {
        if(prime[i] == -1) continue;
        for(int j = 2 * i; j <= 1000000; j += i) {
            if(prime[j] == -1)  continue;
            else prime[j] = -1;
        }
    }

    int n;
    while(true) {
        bool flag = false;
        scanf("%d", &n);
        if(n == 0) break;

        for(int i = n; i >= (n / 2); i--) {
            if(prime[i] >= 0 && prime[n - i] >= 0) {
                printf("%d = %d + %d\n", n, n - i, i);
                flag = true;
                break;
            }
        }
        if(!flag) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}