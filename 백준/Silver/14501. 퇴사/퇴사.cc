#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> v(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++)
        cin >> v[i][0] >> v[i][1];
    
    vector<int> dp(n + 1, 0);
    for (int i = 1; i<= n; i++) {
        int end = i + v[i][0] - 1;
        int sum = dp[i - 1] + v[i][1];
        if (end <= n && dp[end] < sum)
            dp[end] = sum;
        if (dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];
    }
    cout << dp[n] << '\n';
    return 0;
}