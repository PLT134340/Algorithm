#include <iostream>
#include <stack>
using namespace std;

struct pipe {
    int y;
    int x;
    int state;
};

int arr[17][17] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    int result = 0;
    stack<pipe> s;
    s.push(pipe{1, 2, 1}); // (1, 가로), (0, 대각), (-1, 세로)
    while (!s.empty()) {
        auto [y, x, state] = s.top();
        s.pop();

        if (y == n && x == n) {
            result++;
            continue;
        }

        if (x + 1 <= n && y + 1 <= n && arr[y][x + 1] == 0 && arr[y + 1][x] == 0 && arr[y + 1][x + 1] == 0)
            s.push(pipe{y + 1, x + 1, 0});
        if (state >= 0)
            if (x + 1 <= n && arr[y][x + 1] == 0)
                s.push(pipe{y, x + 1, 1});
        if (state <= 0)
            if (y + 1 <= n && arr[y + 1][x] == 0)
                s.push(pipe{y + 1, x, -1});
    }
    
    cout << result << '\n';
    return 0;
}