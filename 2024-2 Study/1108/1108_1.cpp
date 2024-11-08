#include <iostream>
#define MAX 100

using namespace std;

int field[MAX][MAX];
int T, N, K;

int Trash(int startY, int startX);

int main() {
	cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> N >> K;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> field[i][j];

        int range = N - K;

        int min = N * N;

        for(int startY = 0; startY <= range; startY++) {
            for(int startX = 0; startX <= range; startX++) {

                int count = Trash(startY, startX);
                min = count < min ? count : min;
            
            }
        }

        cout << min << endl;
    }
	return 0;
}

int Trash(int startY, int startX) {
    int count = 0;

    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            if(field[i + startY][j + startX]) count++;
        }
    }
    return count;
}