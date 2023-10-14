#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for(int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        pq.push({m, v});
    }
    
    multiset<int> bagSize;
    for(int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bagSize.insert(c);
    }
    
    vector<int> bag;
    while(!pq.empty() && bag.size() < k) {
        auto [m, v] = pq.top();
        pq.pop();
        
        auto it = bagSize.lower_bound(m);
        if(it != bagSize.end()) {
            bag.push_back(v);
            bagSize.erase(it);
        }
    }
    
    long long result = 0;
    for(auto val : bag)
        result += val;
    cout << result << '\n';
    return 0;
}