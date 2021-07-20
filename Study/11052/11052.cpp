#include <cstdio>
#include <vector>

using namespace std;

int DP(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", DP(n));
    return 0;
}

int DP(int n) {
    vector<int> card(n + 1);
    vector<int> price(n + 1, 0);
    for(int i = 1; i <= n; i++) scanf("%d", &card[i]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            price[i] = (price[i] > price[i - j] + card[j] ? price[i] : price[i - j] + card[j]);
        }
    }

    return price[n];
}