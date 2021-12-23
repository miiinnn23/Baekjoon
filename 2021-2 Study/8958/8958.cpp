#include <cstdio>
#include <cstring>

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 0;i < N; i++) {
        char *quiz = new char[80];
        scanf("%s", quiz);

        int score = 0, sum = 0;
        for(int j = 0; j < strlen(quiz); j++) {
            if(quiz[j] == 'O')
                score += 1;
            else score = 0;
            sum += score;
        }
        printf("%d\n", sum);
    }
    return 0;
}