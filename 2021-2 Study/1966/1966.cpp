#include <cstdio>
#include <queue>

using namespace std;

int main(void) {
    int test;

    scanf("%d", &test);
    for(int i = 0; i < test; i++) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        queue<pair<int, int> > print;
        priority_queue<int> check;

        int priority;
        for(int j = 0; j < N; j++) {
            scanf("%d", &priority);
            print.push(make_pair(j, priority));
            check.push(priority);
        }
        
        int count = 0;
        while(!print.empty()) {
            int index = print.front().first;
            int now_priority = print.front().second;

            if(check.top() > now_priority) {
                print.push(print.front());
                print.pop();
            }
            else {
                count++;
                print.pop();
                check.pop();

                if(index == M) {
                    printf("%d\n", count);
                    break;
                }
            }
        }
    }
    return 0;
}