#include <iostream>
using namespace std;

int dp[2][100000];

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> dp[i][j];

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];

        for(int i = 2; i < n; i++)
            for(int j = 0; j < 2; j++)
                dp[j][i] += max(dp[1 - j][i - 1], dp[1 - j][i - 2]);

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    return 0;
}