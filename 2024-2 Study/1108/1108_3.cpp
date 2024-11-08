// https://codingjj.tistory.com/84
#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<string>> answer;
vector<vector<string>> graph;

bool Compare(string banned, string user) {
    int length = banned.length();
    bool is_same = true;

    // 길이 다르면 컷    
    if(user.length() != length) return false;

    for(int i = 0; i < length; i++) {
        if(banned[i] == '*') continue;
        if(banned[i] != user[i]) is_same = false;
    }

    return is_same;
}

void DFS(int idx, set<string> temp) {
    if(idx == graph.size()) {
        answer.insert(temp);
    }

    else{
        for(int i = 0; i < graph[idx].size(); i++) {
            if(temp.find(graph[idx][i]) == temp.end()) {
                set<string> new_set(temp);
                new_set.insert(graph[idx][i]);
                DFS(idx + 1, new_set);
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int banned = banned_id.size();
    int user = user_id.size();
    graph.resize(banned, vector<string>());

    for(int i = 0; i < banned; i++)
        for(int j = 0; j < user; j++)
            if(Compare(banned_id[i], user_id[j])) graph[i].push_back(user_id[j]);

    
    set<string> temp;
    DFS(0, temp);
    
    return answer.size();
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<string> user_id(N);
    vector<string> banned_id(K);

    for(int i = 0; i < N; i++) {
        cin >> user_id[i];
    }

    for(int i = 0; i < K; i++) {
        cin >> banned_id[i];
    }

    cout << solution(user_id, banned_id) << endl;
    return 0;
}

/*
5 2
frodo fradi crodo abc123 frodoc
fr*d* abc1**

5 3
frodo fradi crodo abc123 frodoc
*rodo *rodo ******

5 4
frodo fradi crodo abc123 frodoc
fr*d* *rodo ****** ******
*/