#include <iostream>
#include <string>
#include <stack>
using namespace std;

char matrix[600][600];
bool isVisited[600][600];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;

    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            matrix[i][j] = str[j];
            if(str[j] == 'I') {
                s.push({i, j});
                isVisited[i][j] = true;
            }
        }
    }

    int result = 0;
    while(!s.empty()) {
        auto [y, x] = s.top();
        s.pop();

        if(matrix[y][x] == 'P')
            result++;
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < m && newY >= 0 && newY < n
                && !isVisited[newY][newX] && matrix[newY][newX] != 'X') {
                s.push({newY, newX});
                isVisited[newY][newX] = true;
            }
        }
    }

    if(result == 0)
        cout << "TT\n";
    else
        cout << result << '\n';
    return 0;
}