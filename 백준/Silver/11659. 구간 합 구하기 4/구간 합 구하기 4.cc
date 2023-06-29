#include <iostream>
using namespace std;

int sum[100001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }

    for(int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }
    return 0;
}