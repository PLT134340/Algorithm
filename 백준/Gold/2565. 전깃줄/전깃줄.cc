#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m.insert({a, b});
    }
    
    vector<int> v;
    for(auto it = m.begin(); it != m.end(); it++)
        if(v.empty() || v.back() < it->second)
            v.push_back(it->second);
        else if(v.back() >= it->second)
            *lower_bound(v.begin(), v.end(), it->second) = it->second;
    
    cout << n - v.size() << '\n';
    return 0;
}