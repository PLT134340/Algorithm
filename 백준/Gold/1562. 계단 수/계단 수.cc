#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000000;

int dp[101][10][1024] = {0};  //[길이][끝 숫자][사용된 숫자]

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < 10; i++)
        dp[1][i][1 << i] = 1;
        
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 1024; k++) {
                if (j - 1 >= 0) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                    dp[i][j][k | (1 << j)] %= MOD;
                }
                if (j + 1 < 10) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                    dp[i][j][k | (1 << j)] %= MOD;
                }
            }
    
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += dp[n][i][1023];
        result %= MOD;
    }
    cout << result << '\n';
    return 0;
}