#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    int D, N;
    scanf("%d %d", &D, &N);

    vector<int> oven(D);
    vector<int> pizza(N);
    for(int i = 0; i < D; i++) {
        scanf("%d", &oven[i]);
        if(i != 0 && oven[i - 1] < oven[i]) oven[i] = oven[i - 1];
    }

    for(int i = 0; i < N; i++) {
        scanf("%d", &pizza[i]);
    }

    int count = 0;
    for(int i = D - 1; i >= 0; i--) {
        if(pizza[count] <= oven[i]) count++;
        
        if(count == N) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("0\n");
    return 0;
}