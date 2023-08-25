#include <iostream>
using namespace std;

int dp[21] = {0, 1};

void hanoiTop(int n, int src, int dst);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++)
        dp[i] = 2 * dp[i - 1] + 1;

    cout << dp[n] << '\n';
    hanoiTop(n, 1, 3);
    return 0;
}

void hanoiTop(int n, int src, int dst) {
    if(n == 1)
        cout << src << ' ' << dst << '\n';
    else {
        int stop = 6 - src - dst;
        hanoiTop(n - 1, src, stop);
        cout << src << ' ' << dst << '\n';
        hanoiTop(n - 1, stop, dst);
    }
}