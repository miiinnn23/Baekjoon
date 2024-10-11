#include <iostream>

#define MAX 100001

using namespace std;


// 아마 runtime error(시간초과) 뜨는 코드일것..

int N;

int min(int a, int b) { return a < b ? a : b; }

typedef struct tree {
    int parent;
    int authority;
    bool alert;
    int val;
} Tree;

Tree* chat;

void Input();

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << "(" << i << ", " << chat[i].parent << "), " << chat[i].authority << ", " << chat[i].val << endl;
    }
}

void Calc(int p);

int main(void) {
    int Q;
    cin >> N >> Q;

    chat = new Tree[N + 1];
    chat[0].parent = -1;
    chat[0].authority = -1;

    for(int t = 0; t < Q; t++) {
        int request;
        cin >> request;

        if(request == 100) {
            Input();
            // Print();
        }
        else if(request == 200) {
            int c;
            cin >> c;

            chat[c].alert = chat[c].alert ? false : true;
        }
        else if(request == 300) {
            int c, power;
            cin >> c >> power;

            chat[c].authority = power;
        }
        else if(request == 400) {
            int c1, c2;
            cin >> c1 >> c2;

            int p1 = chat[c1].parent;
            chat[c1].parent = chat[c2].parent;
            chat[c2].parent = p1;
        }
        else if(request == 500) {
            for(int i = 1; i <= N; i++) {
                chat[i].val = 0;
            }
            for(int i = 1; i <= N; i++) {
                Calc(i);
            }
            // Print();
            int c;
            cin >> c;

            cout << chat[c].val << endl;
        }
        else continue;    
    }

    delete[] chat;
    return 0;
}

void Input() {
    for(int i = 1; i <= N; i++) {
        cin >> chat[i].parent;
        chat[i].alert = true;
        chat[i].val = 0;
    }
    for(int i = 1; i <= N; i++) {
        cin >> chat[i].authority;
        chat[i].authority = min(chat[i].authority, 20);
    }
}

void Calc(int p) {
    int power = min(chat[p].authority, 20);
    int now = p;
    int count = 0;

    while(power != 0) {
        if(!chat[now].alert)
            break;
        now = chat[now].parent;
        if(now == 0) break;
        // if(!chat[now].alert)
        //     break;
        
        power--;
        chat[now].val++;
    }
}