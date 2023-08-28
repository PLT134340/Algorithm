#include <iostream>
using namespace std;

int dp[41] = {0, 1, 1};

int main() {
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n] << ' ' << n - 2 << '\n';
    return 0;
}