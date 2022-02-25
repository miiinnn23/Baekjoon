#include <cstdio>
#include <cmath>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    long long int div = b / a;

    long long int num1 = 0, num2 = 0;
    
    for(long long int i = 1; i * i <= div; i++) {
        if(div % i == 0) {
            long long int temp1 = i;
            long long int temp2 = div / i;

            bool flag = true;
            int count = 0;
            for(int i = 1; i <= temp1; i++) {
                if(temp1 % i == 0 && temp2 % i == 0) count++;

                if(count > 1) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                num1 = temp1;
                num2 = temp2;
            }
        }
    }

    printf("%lld %lld\n", num1 * a, num2 * a);
    return 0;
}