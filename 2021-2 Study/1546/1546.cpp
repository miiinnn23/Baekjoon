#include <cstdio>

int main(void) {
    int subject;
    scanf("%d", &subject);

    int *score = new int[subject];
    float *newScore = new float[subject];
    float sum = 0;

    for(int i = 0; i < subject; i++) {
        scanf("%d", &score[i]);
    }

    int max = score[0];
    for(int i = 0; i < subject; i++) { // 최댓값 찾기
        if(max < score[i]) max = score[i];
    }
    
    for(int i = 0; i < subject; i++) { // 점수 재계산
        newScore[i] = ((float)score[i] / max) * 100;
        sum += newScore[i];
    }

    printf("%f\n", sum / subject);

    delete[] newScore;
    delete[] score;
    return 0;
}