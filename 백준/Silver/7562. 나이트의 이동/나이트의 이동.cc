#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int n;
    int y;
    int x;
};

int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int l;
        cin >> l;
        
        int cur_y, cur_x, dest_y, dest_x;
        cin >> cur_y >> cur_x >> dest_y >> dest_x;
        
        queue<Node> q;
        vector<vector<bool>> is_visited(l, vector<bool>(l, false));
        q.push(Node{0, cur_y, cur_x});
        is_visited[cur_y][cur_x] = true;
        
        while (!q.empty()) {
            auto [n, y, x] = q.front();
            q.pop();
            
            if (y == dest_y && x == dest_x) {
                cout << n << '\n';
                break;
            }
            
            for (int j = 0; j < 8; j++) {
                int new_y = y + dy[j];
                int new_x = x + dx[j];
                
                if (new_y >= 0 && new_y < l && new_x >= 0 && new_x < l && !is_visited[new_y][new_x]) {
                    q.push(Node{n + 1, new_y, new_x});
                    is_visited[new_y][new_x] = true;
                }
            }
        }
        
    }
    return 0;
}