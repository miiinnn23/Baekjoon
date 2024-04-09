#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;

    int len = record.size();
    for(int i = 0; i < len; i++) {
        string line = record[i];
        line += " ";
        string del = " ";
        vector<string> text;

        size_t pos = 0;
        while((pos = line.find(del)) != string::npos) {
            text.push_back(line.substr(0, pos));
            line.erase(0, pos + del.length());
        }

        if(text.size() == 2) continue;

        if(user.count(text[1])) user[text[1]] = text[2];
        else user.insert(make_pair(text[1], text[2]));
    }

    for(int i = 0; i < len; i++) {
        string line = record[i];
        string del = " ";

        size_t pos = line.find(del);
        string text = line.substr(0, pos);
        line.erase(0, pos + del.length());
        
        if(text == "Leave") {
            string temp = user[line] + "님이 나갔습니다.";
            answer.push_back(temp);
        }

        else if(text == "Enter") {
            pos = line.find(del);
            text = line.substr(0, pos);
            string temp = user[text] + "님이 들어왔습니다.";
            answer.push_back(temp);
        }

        else continue;
    }

    return answer;
}

int main(void) {
    vector<string> record;
    for(int i = 0; i < 5; i++) {
        string str;
        getline(cin, str);
        record.push_back(str);
    }

    vector<string> answer = solution(record);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}