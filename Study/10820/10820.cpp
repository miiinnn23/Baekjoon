#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string temp;
    
    while(1) {
        getline(cin, temp);
        if(cin.eof()) break;
        
        int count[4] = { 0 }; // [0] : 소문자, [1] : 대문자, [2] : 숫자, [3] : 공백
        for(int i = 0; i < temp.length(); i++) {
            if(temp[i] >= 'a' && temp[i] <= 'z') count[0]++;
            else if(temp[i] >= 'A' && temp[i] <= 'Z') count[1]++;
            else if(temp[i] >= '0' && temp[i] <= '9') count[2]++;
            else count[3]++;
        }
        for(int i = 0; i < 4; i++) {
            printf("%d ", count[i]);
        }
        printf("\n");
    }
    return 0;
}