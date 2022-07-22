#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

vector<int> rope;
bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        rope.push_back(num);
    }
    
    sort(rope.begin(), rope.end(), compare);

    int max = 0;
    for(int i = 0; i < N; i++) {
        int num = rope[i] * (i + 1);
        if(max < num) {
            max = num;
        }
    }

    printf("%d\n", max);
    return 0;
}

