#include <iostream>
using namespace std;

int dp[101][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        for(int j = 1; j <= 8; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        dp[i][9] = dp[i - 1][8];
    }

    int result = 0;
    for(int i = 0; i <= 9; i++) 
        result = (result + dp[n][i]) % 1000000000;
    cout << result << '\n';
    return 0;
}