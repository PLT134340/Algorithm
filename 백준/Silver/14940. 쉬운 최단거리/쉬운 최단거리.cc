#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

bool isVisited[1000][1000] = {false};
int matrix[1000][1000] = {0};
int result[1000][1000] = {0};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    queue<tuple<int, int, int>> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int num;
            cin >> num;
            matrix[i][j] = num;
            if(num == 2) {
                q.push(make_tuple(i, j, 0));
                isVisited[i][j] = true;
            }
        }
    
    while(!q.empty()) {
        auto [y, x, lv] = q.front();
        q.pop();

        result[y][x] = lv;

        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < m && newY >= 0 && newY < n 
                && matrix[newY][newX] == 1 && !isVisited[newY][newX]) {
                q.push(make_tuple(newY, newX, lv + 1));
                isVisited[newY][newX] = true;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == 1 && !isVisited[i][j])
                result[i][j] = -1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}