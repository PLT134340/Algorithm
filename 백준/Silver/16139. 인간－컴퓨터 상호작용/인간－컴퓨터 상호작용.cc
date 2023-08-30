#include <iostream>
#include <string>
using namespace std;

int sum[26][2001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 26; j++)
            sum[j][i] = sum[j][i - 1];
        sum[s[i - 1] - 'a'][i]++;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char a;
        int l, r;
        cin >> a >> l >> r;

        cout << sum[a - 'a'][r + 1] - sum[a - 'a'][l] << '\n';
    }
    return 0;
}