#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    unordered_set<string> hs;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        hs.insert(str);
    }

    vector<string> v;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if(hs.find(str) != hs.end())
            v.push_back(str);
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(auto element: v)
        cout << element << '\n';
    return 0;
}