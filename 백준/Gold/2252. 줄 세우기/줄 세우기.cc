#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> outgoing(n + 1);
    vector<int> incoming(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a != b) {
            outgoing[a].push_back(b);
            incoming[b]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (incoming[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (auto v : outgoing[vertex]) {
            incoming[v]--;
            if (incoming[v] == 0)
                q.push(v);
        }

        cout << vertex << ' ';
    }
    return 0;
}