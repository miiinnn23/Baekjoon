#include <cstdio>
#include <map>
#include <climits>

using namespace std;

map<long long int, bool> mat;
void find(long long int num);

int main(void) {
    int N, M;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        long long int num;
        scanf("%lld", &num);
        mat[num] = true;
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        long long int num;
        scanf("%lld", &num);
        
        find(num);
    }
    return 0;
}

void find(long long int num) {
    long long int left = -(LONG_MAX) - 1;
    long long int right = LONG_MAX;

    while(left <= right) {
        long long int mid = (left + right) / 2;

        if(num == mid) {
            if(mat[num]) printf("1\n");
            else printf("0\n");
            break;
        }
        else if(mid < num) left = mid + 1;
        else right = mid - 1;
    }
}