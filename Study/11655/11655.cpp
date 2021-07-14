#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    getline(cin, str);

    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            int temp = (str[i] - 'a');
            str[i] = (temp + 13) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            int temp = (str[i] - 'A');
            str[i] = (temp + 13) % 26 + 'A';
        }
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}