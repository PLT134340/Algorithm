#include <iostream>
using namespace std;

int dp[21][21][21] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0][0][0] = 1;
    for(int i = 1; i <= 20; i++) {
        dp[0][0][i] = dp[0][i][0] = dp[i][0][0] = 1;
        for(int j = 1; j <= 20; j++) {
            dp[0][i][j] = dp[i][0][j] = dp[i][j][0] = 1;
        }
    }
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= 20; j++)
            for(int k = 1; k <= 20; k++)
                if(i < j && j < k)
                    dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];

    int a, b, c;
    cin >> a >> b >> c;
    while(!(a == -1 && b == -1 && c == -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if(a <= 0 || b <= 0 || c <= 0)
            cout << 1 << '\n';
        else if(a > 20 || b > 20 || c > 20)
            cout << dp[20][20][20] << '\n';
        else 
            cout << dp[a][b][c] << '\n';

        cin >> a >> b >> c;
    }
    return 0;
}