#include <iostream>
#include <string>

using namespace std;
int main(void) {
    string bin;
    long oct;

    cin >> bin;
    int remain = bin.size() % 3;
    int len = bin.size() / 3;

    if(remain == 1) {
        printf("%c", bin[0]);
    }
    else if(remain == 2) {
        printf("%c", ((bin[0] - '0') * 2 + bin[1] - '0') + '0');
    }

    for(int i = remain; i < 3 * len; i += 3) {
        int temp = 0;
        temp += (bin[i] - '0') * 4;
        temp += (bin[i + 1] - '0') * 2;
        temp += (bin[i + 2] - '0');
        printf("%d", temp);
    }
    printf("\n");
    return 0;
}