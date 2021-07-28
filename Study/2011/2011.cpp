#include <cstdio>
#include <iostream>
#include <string>
#define MAX 5001
#define MOD 1000000
// https://yabmoons.tistory.com/163
using namespace std;
int code[MAX];

int DP(int len);
int main(void) {
    string str;
    cin >> str;
    for(int i = 1; i <= str.length(); i++) {
        code[i] = (str[i - 1] - '0');
    }

    printf("%d\n", DP(str.length()));
    return 0;
}

int DP(int len) {
    int D[MAX] = { 0 };
    D[0] = 1;

    if(len == 1 && code[1] == 0) return 0; // 암호가 잘못된 경우

    for(int i = 1; i <= len; i++) {
        if(code[i] > 0) {
            D[i] += (D[i - 1] % MOD);
            D[i] %= MOD;
        }
        
        if(i > 1) {
            int alphabet = code[i - 1] * 10 + code[i];
            if(alphabet >= 10 && alphabet <= 26) {
                D[i] += (D[i - 2] % MOD);
                D[i] %= MOD;
            }
        }
    }

    return D[len];
}