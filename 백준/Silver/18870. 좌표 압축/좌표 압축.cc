#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int result[1000000] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push({x, i});
    }

    int prev = pq.top().first;
    int count = 0;
    while(!pq.empty()) {
        auto [x, idx] = pq.top();
        pq.pop();

        if(prev < x)
            count++;
        
        result[idx] = count;
        prev = x;
    }

    for(int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}