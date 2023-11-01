#include <algorithm>
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
    sort(v.begin(), v.end());

    long long min = INT64_MAX;
    int result[3];
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (i == left) {
                left++;
                continue;
            }
            else if (i == right) {
                right--;
                continue;
            }

            long long sum = (long long)v[i] + v[left] + v[right];
            if (min > abs(sum)) {
                min = abs(sum);
                result[0] = v[left];
                result[1] = v[right];
                result[2] = v[i];
            }
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else {
                sort(result, result + 3);
                for (int i = 0; i < 3; i++)
                    cout << result[i] << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

    sort(result, result + 3);
    for (int i = 0; i < 3; i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}