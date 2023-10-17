#include <iostream>
#include <vector>
using namespace std;

int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    int num[502] = {0};
    int r, c;
    for(int i = 1; i <= n; i++) {
        cin >> r >> c;
        num[i] = r;
    }
    num[n + 1] = c;
    
    for(int k = 1; k < n; k++) {
        for(int i = 1; i <= n - k; i++) {
            int min = INT32_MAX;
            for(int j = i; j < i + k; j++) {
                int tmp = dp[i][j] + dp[j + 1][i + k] + num[i] * num[j + 1] * num[i + k + 1];
                if(min > tmp)
                    min = tmp;
            }
            dp[i][i + k] = min;
        }
    }
    
    cout << dp[1][n] << '\n';
    return 0;
}