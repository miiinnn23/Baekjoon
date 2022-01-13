#include <cstdio>
#include <string>

int main(void) {
    int time[2] = { 0 }; // [0] : 1팀, [1] : 2팀
    int count[2] = { 0 };

    int N;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        int team, min, sec;
        int pastTime;
        scanf("%d %d:%d", &team, &min, &sec);

        if(i > 0) {
            if(count[0] > count[1]) {
                time[0] += (min * 60 + sec - pastTime);
            }
            else if(count[0] < count[1]) {
                time[1] += (min * 60 + sec - pastTime);
            }
        }
        
        count[team - 1]++;
        pastTime = min * 60 + sec;

        if(i == N - 1) {
            if(count[0] > count[1]) {
                time[0] += (48 * 60 - pastTime);
            }
            else if(count[0] < count[1]) {
                time[1] += (48 * 60 - pastTime);
            }
        }
    }
    
    printf("%02d:%02d\n", time[0] / 60, time[0] % 60);
    printf("%02d:%02d\n", time[1] / 60, time[1] % 60);
    return 0;
}