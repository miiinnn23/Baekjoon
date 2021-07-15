#include <iostream>
#include <string>
#include <list>
 
using namespace std;
 
int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    
    list<char> editor(str.begin(),str.end());  
    auto cursor = editor.end();
    
    while(n--){ 
        char command;
        cin >> command;
        
        if(command == 'L'){
            if(cursor != editor.begin()){
                cursor--;
            }
        } 
        else if(command == 'D'){
            if(cursor != editor.end()){
                cursor++;
            }
        }
        else if(command == 'B'){
            if(cursor != editor.begin()){
                cursor = editor.erase(--cursor);
            }
        }
        else if(command == 'P'){
            char x;
            cin >> x;
            editor.insert(cursor, x);
        }    
    }
    for (auto it = editor.begin(); it != editor.end(); it++) {
        cout << *it;
    }
    return 0;     
}