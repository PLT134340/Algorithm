#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

vector<int> sum;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;

        sum = vector<int>(k + 1,0);
        dp = vector<vector<int>>(k + 1, vector<int>(k + 1, INF));
        
        for (int j = 1; j <= k; j++) {
            int tmp;
            cin >> tmp;
            sum[j] = sum[j - 1] + tmp;
            dp[j][j] = 0;
        }
        
        
        for (int j = 1; j < k; j++)
            for (int m = 1; m <= k - j; m++)
                for (int n = m; n < m + j; n++)
                    dp[m][m + j] = min(dp[m][m + j], dp[m][n] + dp[n + 1][m + j] + sum[m + j] - sum[m - 1]);

        cout << dp[1][k] << '\n';
    }
    return 0;
}