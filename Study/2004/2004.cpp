#include <cstdio>
#include <vector>

using namespace std;
long long Min(long long a, long long b) { return a < b ? a : b; }
pair<long long, long long> Count(long long num);

int main(void) {
    long long n, m;
    scanf("%lld %lld", &n, &m);

    vector<pair<long long, long long> > c(3);
    c[0] = Count(n);
    c[1] = Count(m);
    c[2] = Count(n - m);

    printf("%lld\n", Min((c[0].first - c[1].first - c[2].first), (c[0].second - c[1].second - c[2].second)));
    return 0;
}

pair<long long, long long> Count(long long num) {
    long long two = 0, five = 0;
    for(long long i = 2; i <= num; i *= 2) {
        two += num / i;
    }
    for(long long i = 5; i <= num; i *= 5) {
        five += num / i;
    }
    return (pair<long long, long long> (two, five));
}