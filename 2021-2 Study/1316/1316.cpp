#include <cstdio>
#include <cstring>

int main(void) {
    int N;
    int count = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char str[100];
        int alphabet[26] = { 0 };
        scanf("%s", str);

        int length = strlen(str);
        int index = str[0] - 'a';
        alphabet[index] = 1;
        int prevIndex = index;

        for(int j = 1; j < length; j++) {
            index = str[j] - 'a';
            if(alphabet[index] == 0) {
                alphabet[index] = 1;
            }
            else {
                if(index != prevIndex) {
                    count--;
                    break;
                }
            }
            prevIndex = index;
        }
        count++;
    }

    printf("%d\n", count);

    return 0;
}