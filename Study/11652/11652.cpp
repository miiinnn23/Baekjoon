#include <cstdio>
#include <map>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    map<long long, int> card;
    for(int i = 0; i < n; i++) {
        long long temp;
        scanf("%lld", &temp);
        card[temp]++;
    }
    
    map<long long, int>::iterator it = card.begin();
    long long min = __LONG_LONG_MAX__;
    int max = 0;
    
    while(it != card.end()) {
        if(it->second > max) {
            max = it->second;
        }
        it++;
    }

    it = card.begin();
    while(it != card.end()) {
        if(max == it->second) {
            min = it->first < min ? it->first : min;
        }
        it++;
    }
    printf("%lld\n", min);
    return 0;
}