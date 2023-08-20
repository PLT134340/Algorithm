#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool matrix[1001][1001];
bool isVisited[1001][1001][2] = {false};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
            matrix[i][j] = (bool)(str[j] - '0');
    }

    queue<tuple<int, int, int, bool>> q; // {y, x, lv, canBreak}
    q.push(make_tuple(0, 0, 1, true));
    while(!q.empty()) {
        auto [y, x, lv, canBreak] = q.front();
        q.pop();

        if(x == m - 1 && y == n - 1) {
            cout << lv << '\n';
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if(newX >= 0 && newX < m && newY >= 0 && newY < n) {
                if(canBreak) {
                    if(!isVisited[newY][newX][1] && matrix[newY][newX]) {
                        q.push(make_tuple(newY, newX, lv + 1, false));
                        isVisited[newY][newX][1] = true;
                    }
                    if(!isVisited[newY][newX][0] && !matrix[newY][newX]) {
                      q.push(make_tuple(newY, newX, lv + 1, true));
                        isVisited[newY][newX][0] = true;
                    }
                } else if(!isVisited[newY][newX][1] && !matrix[newY][newX]) {
                    q.push(make_tuple(newY, newX, lv + 1, false));
                    isVisited[newY][newX][1] = true;
                }
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}