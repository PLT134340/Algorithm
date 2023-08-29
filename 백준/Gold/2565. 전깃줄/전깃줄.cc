#include <iostream>
using namespace std;

bool line[501][501] = {false};
int dp[501][501] = {0};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        line[a][b] = true;
    }
    
    for(int i = 1; i <= 500; i++)
        for(int j = 1; j <= 500; j++)
            if(line[i][j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                
    cout << n - dp[500][500] << '\n';
    return 0;
}