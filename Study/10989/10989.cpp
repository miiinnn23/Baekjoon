#include <cstdio>
#include <vector>

using namespace std;
// 카운팅정렬
int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> number(10001, 0);

    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        number[temp]++;
    }

    for(int i = 1; i <= 10000; i++) {
        if(number[i] == 0) continue;
        for(int j = 0; j < number[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}