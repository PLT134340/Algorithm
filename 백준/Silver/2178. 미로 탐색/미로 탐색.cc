#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int lv;

    node(int x, int y, int lv)
        :x(x), y(y), lv(lv) {}
};

bool matrix[100][100] = {false};
bool isVisited[100][100] = {true};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
            if(str[j] == '1')
                matrix[i][j] = true;
    }

    queue<node> q;
    q.push(node(0, 0, 1));
    while(!q.empty()) {
        int row = q.front().x;
        int col = q.front().y;
        int lv = q.front().lv;
        q.pop();
        
        if(row == n - 1 && col == m - 1) {
            cout << lv << endl;
            return 0;
        }

        if(col - 1 >= 0 && matrix[row][col - 1] && !isVisited[row][col - 1]) {
            q.push(node(row, col - 1, lv + 1));
            isVisited[row][col - 1] = true;
        }
        if(col + 1 < m && matrix[row][col + 1]&& !isVisited[row][col + 1]) {
            q.push(node(row, col + 1, lv + 1));
            isVisited[row][col + 1] = true;
        }
        if(row - 1 >= 0 && matrix[row - 1][col]&& !isVisited[row - 1][col]) {
            q.push(node(row - 1, col, lv + 1));
            isVisited[row - 1][col] = true;
        }
        if(row + 1 < n && matrix[row + 1][col]&& !isVisited[row + 1][col]) {
            q.push(node(row + 1, col, lv + 1));
            isVisited[row + 1][col] = true;
        }
    }
    return 0;
}