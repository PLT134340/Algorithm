#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> usingMem;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        usingMem.push_back(tmp);
    }
    
    int sum = 0;
    vector<int> restartCost;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        restartCost.push_back(tmp);
    }
    
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
        v.push_back({restartCost[i], usingMem[i]});
    sort(v.begin(), v.end());
    
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for(int num = 1; num <= n; num++)
        for(int cost = 0; cost <= sum; cost++) 
            if(cost == 0 && v[num - 1].first == 0)
                dp[num][cost] = dp[num - 1][cost] + v[num - 1].second;
            else if(v[num - 1].first <= cost)
                dp[num][cost] = max(dp[num - 1][cost - v[num - 1].first] + v[num - 1].second, dp[num - 1][cost]);
            else
                dp[num][cost] = dp[num - 1][cost];  
    
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= sum; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    
    for(int i = 0; i <= sum; i++)
        if(dp[n][i] >= m) {
            cout << i << '\n';
            return 0;
        }
    return 0;
}