#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];

bool compare(pair<int, int>& a, pair<int, int>& b);

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vec(n + 1);
    for(int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        vec[i] = {w, v};
    }
    sort(vec.begin() + 1, vec.end(), compare);
    // for(int i = 1; i <= n; i++)
    //     cout << i << ": " << vec[i].first << ", " << vec[i].second << '\n';

    for(int i = 1; i <= n; i++) {
        auto [weight, profit] = vec[i];
        for(int j = 1; j <= k; j++) {
            if(weight <= j)
                dp[i][j] = max(dp[i - 1][j], profit + dp[i - 1][j - weight]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= k; j++)
    //         cout << '(' << i << ", " << j << "): " << dp[i][j] << '\n';
    cout << dp[n][k] << '\n';
    return 0;
}

bool compare(pair<int, int>& a, pair<int, int>& b) {
    double divA = (double)a.second / a.first;
    double divB = (double)b.second / b.first;

    if(divA > divB)
        return true;
    else
        return false;
}