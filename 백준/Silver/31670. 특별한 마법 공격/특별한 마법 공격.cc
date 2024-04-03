#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    
    vector<vector<long long>> dp(n, vector<long long>(2, 0));  // 없음, 있음
    dp[0][0] = v[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + v[i];  // v[i]를 지움
        dp[i][1] = dp[i - 1][0];  // v[i]를 남김
    }
    
    cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
    // for (int i = 0; i < n; i++) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }
    return 0;
}