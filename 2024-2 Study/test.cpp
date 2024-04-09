#include <cstdio>
#include <cmath>

long long solution(int k, int d) {
        long long answer = 0;

        for(int i = 0; i <= d; i += k) {
                int y = floor(sqrt((long)d*d-(long)i*i));

                answer += y / k + 1;
        }
        return answer;
}

int main(void) {
        int k, d;
        scanf("%d %d", &k, &d);
        printf("%lld\n", solution(k, d));
        return 0;
}