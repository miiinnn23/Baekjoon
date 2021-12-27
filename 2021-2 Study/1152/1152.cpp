#include <iostream>
#include <cstring>
#define MAX 1000000

using namespace std;

int main(void) {
    char sentence[MAX];
    cin.getline(sentence, MAX);

    int count = 0;
    char* ptr = strtok(sentence, " ");

    while(ptr != NULL) {
        count++;
        ptr = strtok(NULL, " ");
    }
    cout << count << "\n";
    return 0;
}