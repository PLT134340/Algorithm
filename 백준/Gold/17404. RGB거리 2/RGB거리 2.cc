#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 10000000;

int main() {
    int n;
    cin >> n;
    
    vector<vector<vector<int>>> dp(3, vector<vector<int>>(n, vector<int>(3)));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            dp[i][0][j] = INF;
            
    for (int i = 0; i < 3; i++)
        cin >> dp[i][0][i];
    
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        for (int j = 0; j < 3; j++) {
            dp[j][i][0] = min(dp[j][i - 1][1], dp[j][i - 1][2]) + a;
            dp[j][i][1] = min(dp[j][i - 1][0], dp[j][i - 1][2]) + b;
            dp[j][i][2] = min(dp[j][i - 1][0], dp[j][i - 1][1]) + c;
        }
    }
    
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for(int k = 0; k < 3; k++)
    //             cout << dp[i][j][k] << ' ';
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    
    cout << min({dp[0][n - 1][1], dp[0][n - 1][2], dp[1][n - 1][0], dp[1][n - 1][2], dp[2][n - 1][0], dp[2][n - 1][1]}) << '\n';
    return 0;
}