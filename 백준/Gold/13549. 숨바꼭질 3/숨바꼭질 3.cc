#include <iostream>
#include <queue>
using namespace std;

bool isVisited[100001] = {false};

int main() {
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q; // {pos, lv}
    q.push({n, 0});
    while(!q.empty()) {
        auto [pos, lv] = q.front();
        q.pop();

        if(pos == k) {
            cout << lv << '\n';
            return 0;
        }

        if(2 * pos <= 100000 && !isVisited[2 * pos]) {
            q.push({2 * pos, lv});
            isVisited[2 * pos] = true;
        }
        if(pos > 0 && !isVisited[pos - 1]) {
            q.push({pos - 1, lv + 1});
            isVisited[pos - 1] = true;
        }
        if(pos < 100000 && !isVisited[pos + 1]) {
            q.push({pos + 1, lv + 1});
            isVisited[pos + 1] = true;
        }
        
    }
    return 0;
}