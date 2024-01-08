#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> dp[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            int sum = dp[i - j] + dp[j];
            if (dp[i] < sum)
                dp[i] = sum;
        }
    
    cout << dp[n] << '\n';
    return 0;
}