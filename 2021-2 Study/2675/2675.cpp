#include <cstdio>
#include <cstring>

int main(void) {
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        int R;
        char* str = new char[20];
        scanf("%d %s", &R, str);

        for(int j = 0; j < strlen(str); j++) {
            for(int k = 0; k < R; k++) {
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
    return 0;
}