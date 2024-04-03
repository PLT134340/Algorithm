#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int max;
};

bool is_visited[2001][1001] = { false };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    set<pair<int, int>> teacher;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        teacher.insert({x, y});
    }
    
    is_visited[0][0] = true;
    queue<Node> q;
    q.push(Node{0, 0, 0});
    
    
    while (!q.empty()) {
        auto [x, y, max] = q.front();
        q.pop();
        
        // cout << x << ' ' << y << ' ' << max << '\n';
        
        if (teacher.find({x, y}) != teacher.end())
            continue;
        
        if (x == 2 * n && y == 0) {
            cout << max << '\n';
            return 0;
        }
        
        if (x + 1 <= n) {
            if (y + 1 <= x + 1 && !is_visited[x + 1][y + 1]) {
                int new_max = std::max(y + 1, max);
                q.push(Node{x + 1, y + 1, new_max});
                is_visited[y + 1][x + 1] = true;
                // cout << "push " << x + 1 << ' ' << y + 1 << '\n';
            }
            if (y - 1 >= 0 && !is_visited[x + 1][y - 1]) {
                q.push(Node{x + 1, y - 1, max});
                is_visited[x + 1][y - 1] = true;
                // cout << "push " << x + 1 << ' ' << y - 1 << '\n';
            }
        } else if (x + 1 <= 2 * n) {
            if (y + 1 <= 2 * n - x - 1 && !is_visited[x + 1][y + 1]) {
                int new_max = std::max(y + 1, max);
                q.push(Node{x + 1, y + 1, new_max});
                is_visited[x + 1][y + 1] = true;
                // cout << "push " << x + 1 << ' ' << y + 1 << '\n';
            } 
            if (y - 1 >= 0 && !is_visited[x + 1][y - 1]) {
                q.push(Node{x + 1, y - 1, max});
                is_visited[x + 1][y - 1] = true;
                // cout << "push " << x + 1 << ' ' << y - 1 << '\n';
            }
        }
    }
    
    cout << -1 << '\n';
    return 0;
}