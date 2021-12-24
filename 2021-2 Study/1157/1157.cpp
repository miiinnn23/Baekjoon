#include <cstdio>
#include <cstring>
#define MAX 1000000

int main(void) {
    int count[26] = { 0 };
    char word[MAX];
    scanf("%s", word);
    
    unsigned long size = strlen(word);
    for(int i = 0; i < size; i++) {
        if(word[i] - 'a' < 0) { //  대문자
            int index = word[i] - 'A';
            count[index]++;
        }
        else {
            int index = word[i] - 'a';
            count[index]++;
        }
    }

    int max = 0, maxidx = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] > max) {
            max = count[i];
            maxidx = i;
        }
        if(max != 0 && i != maxidx && count[i] == max) {
            maxidx = 63 - 'A';
        }
    }

    printf("%c\n", maxidx + 'A');
    return 0;
}