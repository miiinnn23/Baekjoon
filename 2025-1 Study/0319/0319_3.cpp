#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string>
#define MAX 51

using namespace std;

bool visited[MAX] = { false };

int BFS(string begin, string target, vector<string> words) {
    queue<pair<string, int> > q;
    q.push(make_pair(begin, 0));

    while(!q.empty()) {
        string now = q.front().first;
        int step = q.front().second;
        q.pop();

        if(now == target) return step;

        for(int i = 0; i < words.size(); i++) {
            if(!visited[i]) {
                int comp = 0;
                for(int j = 0; j < words[i].size(); j++)
                    if(now[j] != words[i][j]) comp++;

                if(comp == 1) {
                    visited[i] = true;
                    q.push(make_pair(words[i], step + 1));
                }
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    return BFS(begin, target, words);
}

int main(void) {
    int N;
    cin >> N;

    string begin, target;
    cin >> begin >> target;

    vector<string> words(N);
    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    cout << solution(begin, target, words) << endl;
    return 0;
}