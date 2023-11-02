#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> s;

void recurs(int n, vector<int> &edge, vector<bool> &isVisited, int &result);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> edge(n + 1);
        for (int j = 1; j <= n; j++)
            cin >> edge[j];

        int result = 0;
        vector<bool> isVisited(n + 1, false);
        for (int j = 1; j <= n; j++) {
            recurs(j, edge, isVisited, result);
            s.clear();
        }
        cout << n - result << '\n';
    }
    return 0;
}

void recurs(int n, vector<int> &edge, vector<bool> &isVisited, int &result) {
    if (s.find(n) != s.end()) {
        result++;
        int tmp = edge[n];
        while (tmp != n) {
            result++;
            tmp = edge[tmp];
        }
        return;
    } else if (isVisited[n])
        return;
    else {
        s.insert(n);
        isVisited[n] = true;

        recurs(edge[n], edge, isVisited, result);

        s.erase(n);
    }
}