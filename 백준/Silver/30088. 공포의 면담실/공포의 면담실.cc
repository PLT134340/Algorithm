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
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        
        v.push_back(sum);
    }
    
    sort(v.begin(), v.end());
    
    vector<int> sum(n);
    sum[0] = v[0];
    for (int i = 1; i < n; i++)
        sum[i] += sum[i - 1] + v[i];
    
    long long result = 0;
    for (int i = 0; i < n; i++)
        result += sum[i];
    cout << result << '\n';
    return 0;
}