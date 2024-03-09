#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> outgoing(n + 1, vector<int>());
    vector<int> ingoing(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        outgoing[a].push_back(b);
        ingoing[b]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
        if (ingoing[i] == 0)
            pq.push(i);
    
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        
        cout << top << ' ';
        
        for (int num : outgoing[top]) {
            ingoing[num]--;
            if (ingoing[num] == 0)
                pq.push(num);
        }
    }
    return 0;
}