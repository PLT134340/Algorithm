#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (v.empty() || v.back() < num)
            v.push_back(num);
        else
            *lower_bound(v.begin(), v.end(), num) = num;
    }
    
    cout << v.size() << '\n';
    return 0;
}