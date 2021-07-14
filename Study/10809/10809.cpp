#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    string word;
    cin >> word;

    vector<char> character(26, -1);

    for(int i = 0; i < word.length(); i++) {
        int temp = (word[i] - 'a');
        if(character[temp] >= 0) continue;
        else 
            character[temp] = i;
    }

    for(int i = 0; i < character.size(); i++) {
        printf("%d ", character[i]);
    }
    printf("\n");
    return 0;
}