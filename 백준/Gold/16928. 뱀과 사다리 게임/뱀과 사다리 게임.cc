#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

bool isVisited[101] = {false};

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> hm;
    for(int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        hm.insert({x, y});
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()) {
        auto [pos, lv] = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++) {
            int newPos = pos + i;
            if(newPos > 100)
                continue;
            else if(newPos == 100) {
                cout << lv + 1;
                return 0;
            } else
                while(hm.find(newPos) != hm.end())
                    newPos = hm[newPos];
            
            if(!isVisited[newPos]) {
                q.push({newPos, lv + 1});
                isVisited[newPos] = true;
            }
        }
    }
    return 0;
}