// https://dingcoding.tistory.com/101
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
struct Tree {
    int r, c, age;
    bool operator<(const Tree &t) const {
		return age < t.age;
	}
};

vector<vector<int> > board;
vector<vector<int> > A;
vector<Tree> tree;

int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 }; // 8방향 나무 설계
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

void Four_seasons();

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M >> K;

    board.resize(N + 1, vector<int> (N + 1, 5)); // (r, c)는 (1, 1)부터 시작
    A.resize(N + 1, vector<int> (N + 1, 0));     // (r, c)는 (1, 1)부터 시작

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> A[i][j];
    
    for(int i = 0; i < M; i++) {
        int r, c, age;
        cin >> r >> c >> age;
        tree.push_back({r, c, age});
    }
    
    sort(tree.begin(), tree.end());
    Four_seasons();

    return 0;
}

void Four_seasons() {
    for(int year = 0; year < K; year++) {
        // Spring -> Autumn
        vector<Tree> new_tree;
        
        int tree_size = tree.size();

        for(int i = 0; i < tree_size; i++) {
            if(tree[i].age == 0) continue;

            int r = tree[i].r, c = tree[i].c;
            if(board[r][c] >= tree[i].age) {
                board[r][c] -= tree[i].age;
                tree[i].age++;

                if(tree[i].age % 5 == 0) {
                    for(int j = 0; j < 8; j++) {
                        if(r + dy[j] <= 0 || r + dy[j] > N || c + dx[j] <= 0 || c + dx[j] > N) continue;

                        new_tree.push_back({r + dy[j], c + dx[j], 1});
                    }
                }
            }
            else {
                tree[i].age *= -1;
            }
        }

        for(int i = 0; i < tree_size; i++) {
            if(tree[i].age < 0) {
                int r = tree[i].r, c = tree[i].c, age = tree[i].age * -1;
                board[r][c] += age / 2;
            }
            else {
                new_tree.push_back(tree[i]);
            }   
        }

        // Winter
       for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                board[i][j] += A[i][j];

        tree.swap(new_tree);
    }

    cout << tree.size() << "\n";
}