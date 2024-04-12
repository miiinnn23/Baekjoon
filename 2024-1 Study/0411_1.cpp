#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> sum;

    int height = triangle.size();
    sum.push_back({ 0, triangle[0][0], 0 });

    for(int i = 1; i < height; i++) {
        vector<int> temp(i + 3, 0);
        for (int j = 1; j <= i + 1; j++) {
            temp[j] = max(sum[i - 1][j - 1] + triangle[i][j - 1], sum[i - 1][j] + triangle[i][j - 1]);
            answer = max(answer, temp[j]);
        }
        sum.push_back(temp);
    }
    return answer;
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<int> > triangle;
    for(int i = 1; i <= N; i++) {
        vector<int> temp;
        for(int j = 1; j <= i; j++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        triangle.push_back(temp);
    }

    cout << solution(triangle) << endl;
    return 0;
}