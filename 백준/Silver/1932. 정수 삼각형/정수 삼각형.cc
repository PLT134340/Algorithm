#include <iostream>
using namespace std;

int num[501][501] = {0};
int dp[501][501] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> num[i][j];
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = num[i][j] + ((dp[i - 1][j - 1] > dp[i - 1][j]) ? dp[i - 1][j - 1] : dp[i - 1][j]);

    int max = 0;
    for(int i = 1; i <= n; i++)
        if(max < dp[n][i])
            max = dp[n][i];
    cout << max << '\n';
    return 0;
}