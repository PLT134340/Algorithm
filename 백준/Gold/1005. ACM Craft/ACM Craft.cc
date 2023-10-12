#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> buildTime(n + 1);
        for (int j = 1; j <= n; j++)
            cin >> buildTime[j];

        vector<vector<int>> incoming(n + 1);
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            incoming[y].push_back(x);
        }

        int w;
        cin >> w;
        queue<pair<int, int>> q; // {num, timeSum}
        q.push({w, buildTime[w]});
        vector<int> dp(n + 1, 0);
        while (!q.empty()) {
            auto [num, timeSum] = q.front();
            q.pop();
            
            if(dp[num] < timeSum)
                dp[num] = timeSum;

            for (int j = 0; j < incoming[num].size(); j++) {
                int newNum = incoming[num][j];
                int newTimeSum = dp[num] + buildTime[newNum];
                if (dp[newNum] < newTimeSum) {
                    dp[newNum] = newTimeSum;
                    q.push({newNum, newTimeSum});
                }
            }
        }

        int result = 0;
        for (int j = 1; j <= n; j++)
            if (result < dp[j])
                result = dp[j];
        cout << result << '\n';
    }
    return 0;
}