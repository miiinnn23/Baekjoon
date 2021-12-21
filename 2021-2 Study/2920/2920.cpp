#include <cstdio>

int main(void) {
    int before, status;
    int melody[8];

    for(int i = 0; i < 8; i++) {
        scanf("%d", &melody[i]);
    }

    before = melody[0];

    for(int i = 1; i < 8; i++) {
        if(melody[0] == 1) { // ascending
            if(before > melody[i]) {
                status = 2;
                break;
            }
            else status = 0;
        }
        else if(melody[0] == 8) { // descending
            if(before < melody[i]) {
                status = 2;
                break;
            }
            else status = 1;
        }
        else status = 2; // mixed

        before = melody[i];
    }

    switch(status) {
        case 0:
        printf("ascending\n");
        break;
        case 1:
        printf("descending\n");
        break;
        default:
        printf("mixed\n");
        break;
    }
    return 0;
}