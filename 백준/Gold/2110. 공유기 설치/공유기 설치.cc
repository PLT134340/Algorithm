#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    int start = 1;
    int end = v[n - 1] - v[0];
    int result = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int num_router = 1;
        int prev_router = v[0];
        
        for (int i = 1; i < n; i++)
            if (v[i] - prev_router >= mid) {
                num_router++;
                prev_router = v[i];
            }
        
        if (num_router < c)
            end = mid - 1;
        else if (num_router >= c) {
            if (result < mid)
                result = mid;
            start = mid + 1;
        }
    }
    
    cout << result << '\n';
    return 0;
}