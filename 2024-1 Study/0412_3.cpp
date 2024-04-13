#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 51

using namespace std;

bool visited[MAX] = { false };
int cnt[MAX] = { 0 };

int BFS(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));

    while(!q.empty()) {
        string temp = q.front().first;
        int count = q.front().second;

        if(temp == target) {
            return count;
        }
        q.pop();

        for(int i = 0; i < words.size(); i++) {
            if(!visited[i]) {
                int comp = 0;
                for(int j = 0; j < words[i].length(); j++) {
                    if(words[i][j] != temp[j]) comp++;
                }
                if(comp == 1) {
                    visited[i] = true;
                    cnt[i] = count + 1;
                    q.push(make_pair(words[i], cnt[i]));
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
    string begin, target;
    int N;
    cin >> begin >> target;

    cin >> N;

    vector<string> words;
    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    cout << solution(begin, target, words) << endl;
    return 0;
}