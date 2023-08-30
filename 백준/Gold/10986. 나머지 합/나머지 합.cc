#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(m);
    int remainder = 0;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        remainder = (remainder + tmp) % m;
        v[remainder].push_back(i);
    }
    
    long long result = v[0].size();
    for(int i = 0; i < m; i++)
        result += ((long long)v[i].size() * (v[i].size() - 1)) / 2;
    cout << result << '\n';
    return 0;
}