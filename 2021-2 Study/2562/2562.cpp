#include <cstdio>

int main(void) {
    int arr[9] = { 0 };

    for(int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int index = 0;

    for(int i = 1; i < 9; i++) {
        if(max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }

    printf("%d\n%d\n", max, index + 1);
    return 0;
}