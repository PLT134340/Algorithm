#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int matrix[101][101][101];

int main() {
    int m, n, h;
    cin >> m >> n >> h;
    queue<tuple<int, int, int, int>> q;
    bool isRipen = false;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= m; k++) {
                int tmp;
                cin >> tmp;
                matrix[i][j][k] = tmp;
                if(tmp == 1) {
                    q.push(make_tuple(i, j, k, 0));
                    isRipen = true;
                }
            }
    
    if(!isRipen){
        cout << -1 << '\n';
        return 0;
    }

    while(true) {
        auto [z, y, x, lv] = q.front();
        q.pop();

        if(z - 1 >= 1 && matrix[z - 1][y][x] == 0) {
            matrix[z - 1][y][x] = 1;
            q.push(make_tuple(z - 1, y, x, lv + 1));
        } 
        if(z + 1 <= h && matrix[z + 1][y][x] == 0) {
            matrix[z + 1][y][x] = 1;
            q.push(make_tuple(z + 1, y, x, lv + 1));
        } 
        if(y - 1 >= 1 && matrix[z][y - 1][x] == 0) {
            matrix[z][y - 1][x] = 1;
            q.push(make_tuple(z, y - 1, x, lv + 1));
        } 
        if(y + 1 <= n && matrix[z][y + 1][x] == 0) {
            matrix[z][y + 1][x] = 1;
            q.push(make_tuple(z, y + 1, x, lv + 1));
        } 
        if(x - 1 >= 1 && matrix[z][y][x - 1] == 0) {
            matrix[z][y][x - 1] = 1;
            q.push(make_tuple(z, y, x - 1, lv + 1));
        } 
        if(x + 1 <= m && matrix[z][y][x + 1] == 0) {
            matrix[z][y][x + 1] = 1;
            q.push(make_tuple(z, y, x + 1, lv + 1));
        }

        if(q.empty()) {
            for(int i = 1; i <= h; i++)
                for(int j = 1; j <= n; j++)
                    for(int k = 1; k <= m; k++)
                        if(matrix[i][j][k] == 0) {
                            cout << -1 << '\n';
                            return 0;
                        }
            
            cout << lv << '\n';
            return 0;
        }
    }
    return 0;
}