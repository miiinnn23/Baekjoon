#include <cstdio>
#include <vector>

using namespace std;

vector<int> A;
vector<int> Increase(int n);
vector<int> Decrease(int n);
int sum(vector<int> Inc, vector<int> Dec);

int main(void) {
    int n;
    scanf("%d", &n);
    A.resize(n + 1);

    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    printf("%d\n", sum(Increase(n), Decrease(n)));
    return 0;
}

vector<int> Increase(int n) {
    vector<int> Inc(n + 1);
    for(int i = 1; i <= n; i++) {
        Inc[i] = 1;
        for(int j = 1; j < i; j++) {
            if(A[i] > A[j] && Inc[i] < Inc[j] + 1) {
                Inc[i]++;
            }
        }
    }
    return Inc;
}

vector<int> Decrease(int n) {
    vector<int> Dec(n + 1);
    for(int i = n; i > 0; i--) {
        Dec[i] = 1;
        for(int j = n; j >= i; j--) {
            if(A[i] > A[j] && Dec[i] < Dec[j] + 1) {
                Dec[i]++;
            }
        }
    }

    return Dec;
}

int sum(vector<int> Inc, vector<int> Dec) {
    int max = 0;
    for(int i = 1; i < Inc.size(); i++) {
        max = (Inc[i] + Dec[i] > max ? Inc[i] + Dec[i] : max);
    }
    return max - 1;
}