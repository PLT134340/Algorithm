#include <iostream>
using namespace std;

const int INF = 100000000;

int num[100000];
int dp[100000][10];  // {(0, 1), (0, 2), (0, 3), (0, 4), (1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)}
int row[4][4] = {
    {0, 4, 5, 6},
    {1, 4, 7, 8},
    {2, 5, 7, 9},
    {3, 6, 8, 9}
};
int weight[10][10] = {
    {1, 3, 4, 3, INF, INF, INF, INF, INF, INF}, // (0, 1)
    {3, 1, 3, 4, INF, INF, INF, INF, INF, INF}, // (0, 2)
    {4, 3, 1, 3, INF, INF, INF, INF, INF, INF}, // (0, 3)
    {3, 4, 3, 1, INF, INF, INF, INF, INF, INF}, // (0, 4)
    {2, 2, INF, INF, 1, 3, 4, 4, 3, INF}, // (1, 2)
    {2, INF, 2, INF, 3, 1, 3, 3, INF, 3}, // (1, 3)
    {2, INF, INF, 2, 4, 3, 1, INF, 3, 4}, // (1, 4)
    {INF, 2, 2, INF, 4, 3, INF, 1, 3, 4}, // (2, 3)
    {INF, 2, INF, 2, 3, INF, 3, 3, 1, 3}, // (2, 4)
    {INF, INF, 2, 2, INF, 3, 4, 4, 3, 1} // (3, 4)
};

int main() {
    int tmp, n = 0;
    cin >> tmp;
    while (tmp != 0) {
        num[n++] = tmp;
        cin >> tmp;
    }
    
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    for (int i = 0; i < 10; i++)
        dp[0][i] = INF;
    dp[0][num[0] - 1] = 2;
    
    for (int i = 1; i < n; i++)
        for (int j = 0, k = 0; j < 10; j++) {
            if (k >= 4 || j != row[num[i] - 1][k])
                dp[i][j] = INF;
            else {
                int min = INT32_MAX;
                for (int l = 0; l < 10; l++)
                    if (min > dp[i - 1][l] + weight[j][l])
                        min = dp[i - 1][l] + weight[j][l];
                
                if (min >= INF)
                    dp[i][j] = INF;
                else
                    dp[i][j] = min;
                k++;
            }
        }
    
    // for(int i = 0; i < n; i++) {
    //     for (int j = 0; j < 10; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    
    int result = dp[n - 1][0];
    for (int i = 1; i < 10; i++)
        if (result > dp[n - 1][i])
            result = dp[n - 1][i];
    cout << result << '\n';
    return 0;
}