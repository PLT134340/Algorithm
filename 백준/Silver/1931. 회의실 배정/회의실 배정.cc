#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for(int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        pq.push({first, second});
    }

    pair<int, int> prev = pq.top();
    pq.pop();
    int result = 1;
    while(!pq.empty()) {
        if(pq.top().first >= prev.second) {
            prev = pq.top();
            result++;
        }
        pq.pop();
    }

    cout << result << '\n';
    return 0;
}