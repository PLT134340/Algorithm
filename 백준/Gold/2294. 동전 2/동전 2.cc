#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    
    vector<int> dp(k + 1, 10001);
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i >= coin[j] && dp[i] > dp[i - coin[j]] + 1)
                dp[i] = dp[i - coin[j]] + 1;
    
    if (dp[k] == 10001)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
    return 0;
}