#include <iostream>
#define MAX 101

// 누적합 사용
using namespace std;

int field[MAX][MAX];
int T, N, K;

int Trash(int y, int x);

int main() {
	cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> N >> K;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> field[i][j];

        int sum[MAX][MAX] = { 0 };

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                sum[i][j] = field[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
        
        int range = N - K;
        int min = N * N;

        for(int y = 0; y <= range; y++) {
            for(int x = 0; x <= range; x++) {
                int count = sum[y + K][x + K] - sum[y][x + K] - sum[y + K][x] + sum[y][x];
                min = count < min ? count : min;
            }
        }

        cout << min << endl;
    }
	return 0;
}

