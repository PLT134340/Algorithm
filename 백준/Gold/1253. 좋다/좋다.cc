#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int sum = v[left] + v[right];
            if (sum < v[i])
                left++;
            else if (sum > v[i])
                right--;
            else if (left == i)
                left++;
            else if (right == i)
                right--;
            else {
                // cout << "sum: " << sum << ", left: " << left << ", right: " << right << '\n'; 
                result++;
                break;
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}