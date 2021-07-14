#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    //char* word;
    string word;
    cin >> word;
    //scanf("%s", word);

    vector<char> character(26, 0);

    for(int i = 0; i < word.length(); i++) {
        int temp = (word[i] - 'a');
        character[temp]++;
    }

    for(int i = 0; i < character.size(); i++) {
        printf("%d ", character[i]);
    }
    printf("\n");
    return 0;
}