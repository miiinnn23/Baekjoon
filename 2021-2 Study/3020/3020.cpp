#include <cstdio>
#include <climits>

int main(void) {
    int N, H;
    scanf("%d %d", &N, &H);

    int *up = new int[H + 1];
    int *down = new int[H + 1];

    for(int i = 0; i <= H; i++) {
        up[i] = down[i] = 0;
    }

    for(int i = 0; i < N; i++) {
        int height;
        scanf("%d", &height);

        if(i % 2 == 0) down[height]++;
        else up[height]++;
    }

    for(int i = H - 1; i >= 0; i--) {
        up[i] += up[i + 1];
        down[i] += down[i + 1];
    }

    int min = INT_MAX, count = 0;
    for(int i = 1; i <= H; i++) {
        int obstacle = down[i] + up[H - i + 1];
        if(min > obstacle) {
            min = obstacle;
            count = 1;
        }
        else if(min == obstacle) count++;
    }

    printf("%d %d\n", min, count);

    delete[] up;
    delete[] down;
    return 0;
}