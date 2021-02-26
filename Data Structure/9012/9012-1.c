#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void) {
    int count = 0;
    int i, j, flag;
    scanf("%d", &count);
    
    for(i = 0; i < count; i++) {
        char temp[MAX];
        scanf("%s", temp);
        flag = 0;

        j = 0;
        for(j = 0; j < strlen(temp); j++) {
            switch (temp[j]) {
                case '(':
                flag += 1;
                break;
                case ')':
                flag -= 1;
                break;
                default:
                break;
            }
            if(flag < 0) {
                printf("NO\n");
                break;
            }
        }
        if(flag == 0) {
            printf("YES\n");
        } else if(flag > 0) {
            printf("NO\n");
        }
    }
}