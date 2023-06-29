#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        pq.push(p);
    }

    int result = 0;
    int prev = 0;
    while(!pq.empty()) {
        prev += pq.top();
        pq.pop();
        result += prev;
    }
    cout << result << '\n';
    return 0;
}