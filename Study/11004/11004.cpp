#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> num(n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    sort(num.begin(), num.end());
    printf("%d\n", num[k - 1]);
    return 0;
}