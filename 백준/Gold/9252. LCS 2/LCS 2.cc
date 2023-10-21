#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1;
    string str2;
    cin >> str1 >> str2;

    int str2Size = str2.size();
    int str1Size = str1.size();
    vector<vector<int>> dp(str2Size + 1, vector<int>(str1Size + 1, 0));
    for (int i = 1; i <= str2Size; i++)
        for (int j = 1; j <= str1Size; j++)
            if (str2[i - 1] == str1[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
    // for (int i = 0; i <= str2Size; i++) {
    //     for (int j = 0; j <= str1Size; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }

    vector<char> result;
    int i = str2Size;
    int j = str1Size;
    while (dp[i][j] > 0)
        if(dp[i][j] == dp[i - 1][j - 1]) {
            i--;
            j--;
        } else if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else {
            result.push_back(str2[i - 1]);
            i--;
            j--;
        }

    cout << dp[str2Size][str1Size] << '\n';
    for (auto it = result.rbegin(); it != result.rend(); it++)
        cout << *it;
    cout << '\n';
    return 0;
}