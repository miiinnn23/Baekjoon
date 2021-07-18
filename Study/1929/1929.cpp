#include <cstdio>
#include <vector>

using namespace std;

bool IsPrime(int num);

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    // 풀이 #01
    for(int i = m; i <= n; i++) {
        if(IsPrime(i)) printf("%d\n", i);
    }
    // 풀이 #02
    vector<int> arr(n + 1, 0);

    for(int i = 2; i <= n; i++) {
        arr[i] = i;
    }

    for(int i = 2; i * i <= n; i++) {
        if(arr[i] == 0) continue;
        for(int j = 2 * i; j <= n; j += i) {
            if(arr[j] == 0)  continue;
            else arr[j] = 0;
        }
    }

    for(int i = m; i <= n; i++) {
        if(arr[i] != 0) printf("%d\n", arr[i]);
    }
    return 0;
}

bool IsPrime(int num) {
    if(num <= 1) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}