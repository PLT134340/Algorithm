#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int matrix[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int m, n;
    cin >> m >> n;

    queue<tuple<int, int, int>> q;
    bool isRipen = false;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            int tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
            if(tmp == 1) {
                q.push(make_tuple(i, j, 0));
                isRipen = true;
            }
        }

    if(!isRipen) {
        cout << -1 << '\n';
        return 0;
    }

    while(true) {
        auto [y, x, lv] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
            if(x + dx[i] >= 1 && x + dx[i] <= m && y + dy[i] >= 1 && y + dy[i] <= n && matrix[y + dy[i]][x + dx[i]] == 0) {
                matrix[y + dy[i]][x + dx[i]] = 1;
                q.push(make_tuple(y + dy[i], x + dx[i], lv + 1));
            }
        
        if(q.empty()) {
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                    if(matrix[i][j] == 0) {
                        cout << -1 << '\n';
                        return 0;
                    } 
            cout << lv << '\n';
            return 0;
        }
    }
    return 0;
}