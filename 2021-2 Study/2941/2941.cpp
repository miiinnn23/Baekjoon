#include <cstdio>
#include <cstring>

int main(void) {
    char word[100];
    scanf("%s", word);
    int n = strlen(word);
    int count = 0, i = 0;

    while(i < n) {
        if(i < n - 1) {
            if(word[i] == 'c' && (word[i + 1] == '=' || word[i + 1] == '-')) {
                i += 2;
            }
            else if(word[i] == 'd' && word[i + 1] == '-') {
                i += 2;
            }
            else if(word[i] == 'l' && word[i + 1] == 'j') {
                i += 2;
            }
            else if(word[i] == 'n' && word[i + 1] == 'j') {
                i += 2;
            }
            else if(word[i] == 's' && word[i + 1] == '=') {
                i += 2;
            }
            else if(word[i] == 'z' && word[i + 1] == '=') {
                if(i > 0 && word[i - 1] == 'd') count--;
                i += 2;
            }
            else i++;
        }
        else i++;

        count++;
    }

    printf("%d\n", count);
    return 0;
}