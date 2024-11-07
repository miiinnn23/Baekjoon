#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define MAX 10001

using namespace std;

map<string, int> airport;
vector<string> answer_temp;
int ticket_no;
bool is_used = false;
vector<vector<pair<bool, string>>> graph;

vector<string> solution(vector<vector<string>> tickets);
void DFS(int arrival, int ticket) {
    if(ticket == ticket_no) is_used = true;

    for(auto& i:graph[arrival - 1]) {
        if(!i.first) {
            i.first = true;
            answer_temp.push_back(i.second);
            DFS(airport[i.second], ++ticket);

            if(!is_used) {
                i.first = false;
                answer_temp.pop_back();
            }
        }
    }
}


int main(void) {
    int N;
    cin >> N;

    vector<vector<string>> tickets;
    for(int i = 0; i < N; i++) {
        vector<string> temp(2);
        cin >> temp[0] >> temp[1];        
        tickets.push_back(temp);
    }

    vector<string> answer = solution(tickets);
    cout << endl;

    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());

    ticket_no = tickets.size();

    int count = 1;
    for(auto&i : tickets) {
        for(auto& j : i) {
            if(airport[j]) continue;
            airport[j] = count;
            count++;
        }
    }
    
    int airport_count = count - 1;
    graph.resize(airport_count, vector<pair<bool, string>> ());

    for(auto&i : tickets) {
        int arrival = airport[i[0]];

        graph[arrival - 1].push_back(make_pair(false, i[1]));
    }

    answer_temp.push_back("ICN");

    DFS(airport["ICN"], 0);

    answer = answer_temp;

    return answer;
}