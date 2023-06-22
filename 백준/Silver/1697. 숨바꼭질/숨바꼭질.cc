#include <iostream>
#include <queue>
using namespace std;

bool isVisited[100001] = {false};

int main() {
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()) {
        int pos = q.front().first;
        int lv = q.front().second;
        q.pop();

        if(pos == k) {
            cout << lv << endl;
            return 0;
        } else {
            if(pos - 1 >= 0 && !isVisited[pos - 1]) {
                q.push({pos - 1, lv + 1});
                isVisited[pos - 1] = true;
            }
            if(pos + 1 <= 100000 && !isVisited[pos + 1]) {
                q.push({pos + 1, lv + 1});
                isVisited[pos + 1] = true;
            }
            if(pos != 0 && pos * 2 <= 100000 && !isVisited[pos * 2]) {
                q.push({pos * 2, lv + 1});
                isVisited[pos * 2] = true;
            }
        }
    }
    return 0;
}