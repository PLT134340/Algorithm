#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    cin >> str;
    
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    
    for (int i = 0; i < n - 1; i++)
        if (str[i] == str[i + 1])
            dp[i][i + 1] = 1;
    
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < n - i; j++)
            if (dp[j + 1][j + i - 1] == 1 && str[j] == str[j + i])
                dp[j][j + i] = 1;
    
    vector<int> result(n, 0);
    result[0] = 1;
    for (int i = 1; i < n; i++)
        if (dp[0][i] == 1)
            result[i] = 1;
        else {
            int min = result[i - 1] + 1;
            for (int j = 0; j < i; j++)
                if (min > result[j] + dp[j + 1][i])
                    min = result[j] + dp[j + 1][i];
            result[i] = min;
        }
    
    cout << result[n - 1] << '\n';
    return 0;
}