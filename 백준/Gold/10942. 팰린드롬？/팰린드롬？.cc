#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; i - j >= 0 && i + j < n && j < n; j++)
            if (v[i - j] == v[i + j])
                isPalindrome[i - j][i + j] = true;
            else
                break;

        for (int j = 0; i - j >= 0 && i + j + 1 < n && j < n - 1; j++)
            if (v[i - j] == v[i + j + 1])
                isPalindrome[i - j][i + j + 1] = true;
            else
                break;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        if (isPalindrome[s - 1][e - 1])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}