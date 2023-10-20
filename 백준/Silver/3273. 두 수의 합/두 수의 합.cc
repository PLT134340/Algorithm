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

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int x;
    cin >> x;

    int start = 0;
    int end = v.size() - 1;
    int result = 0;
    while (start < end) {
        int sum = v[start] + v[end];
        if (sum == x) {
            result++;
            start++;
            end--;
        } else if (sum > x)
            end--;
        else
            start++;
    }
    
    cout << result << '\n';
    return 0;
}