#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dp;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        
        if (dp.empty() || dp.back() < v[i]) {
            dp.push_back(v[i]);
            dist[i] = dp.size() - 1;
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), v[i]);
            *it = v[i];
            dist[i] = it - dp.begin();
        }
        
    }
    
    vector<int> result(dp.size());
    for (int i = n - 1, order = dp.size() - 1; i >= 0 && order >= 0; i--)
        if (dist[i] == order)
            // cout << "order: " << order << ", i: " << i << ", v[i]: " << v[i] << '\n';
            result[order--] = v[i];
    
    cout << dp.size() << '\n';
    for (auto value : result)
        cout << value << ' ';
    return 0;
}