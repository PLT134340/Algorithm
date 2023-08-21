#include <iostream>
#include <stack>
using namespace std;

int map[8][8] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maxSafeZone(int n, int m);

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];

    cout << maxSafeZone(n, m) << '\n';
    return 0;
}

int maxSafeZone(int n, int m) {
    int max = 0;
    for(int a = 0; a < n * m - 2; a++)
        for(int b = a + 1; b < n * m - 1; b++)
            for(int c = b + 1; c < n * m; c++)
                if(map[a / m][a % m] == 0 && map[b / m][b % m] == 0 && map[c / m][c % m] == 0) {
                    stack<pair<int, int>> s;
                    bool isVisited[8][8] = {false};
                    int newMap[8][8];
                    for(int i = 0; i < n; i++)
                        for(int j = 0; j < m; j++) {
                            newMap[i][j] = map[i][j];
                            if(map[i][j] == 2) {
                                s.push({i, j});
                                isVisited[i][j] = true;
                            }
                        }
                    newMap[a / m][a % m] = newMap[b / m][b % m] = newMap[c / m][c % m] = 1;
                    
                    while(!s.empty()) {
                        auto [y, x] = s.top();
                        s.pop();

                        for(int i = 0; i < 4; i++) {
                            int newY = y + dy[i];
                            int newX = x + dx[i];
                            if(newY >= 0 && newY < n && newX >= 0 && newX < m && newMap[newY][newX] == 0 && !isVisited[newY][newX]) {
                                newMap[newY][newX] = 2;
                                s.push({newY, newX});
                                isVisited[newY][newX] = true;
                            }
                        }
                    }

                    int result = 0;
                    for(int i = 0; i < n; i++)
                        for(int j = 0; j < m; j++)
                            if(newMap[i][j] == 0)
                                result++;

                    if(max < result)
                        max = result;
                }
    return max;
}