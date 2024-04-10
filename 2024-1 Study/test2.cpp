#include <cstdio>

int solution(int n, int a, int b) {
    int answer = 0;
    while(a != b) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }
    return answer;
}

int main(void) {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    printf("%d\n", solution(N, A, B));
    return 0;
}