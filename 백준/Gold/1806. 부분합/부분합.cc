#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> v(n, 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int result = INT32_MAX;
    int i = 0, j = 1;
    int sum = v[0];
    while (j <= n)
        if (sum >= s) {
            int tmp = j - i;
            if (result >= tmp)
                result = tmp;
            sum -= v[i++];
        } else if(j < n)
            sum += v[j++];
        else
            j++;

    if (result == INT32_MAX)
        cout << 0 << '\n';
    else
        cout << result << '\n';
    return 0;
}