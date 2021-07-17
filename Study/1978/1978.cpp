#include <cstdio>
#include <vector>

using namespace std;

bool IsPrime(int num);

int main(void) {
    int n;
    scanf("%d", &n);
    
    int result = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if(IsPrime(temp)) result++;
    }

    printf("%d\n", result);
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