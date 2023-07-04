#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int result[100001];

void root(vector<unordered_set<int>>& v, int parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<unordered_set<int>> v(n + 1);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }

    root(v, 1);

    for(int i = 2; i <= n; i++)
        cout << result[i] << '\n';
    return 0;
}

void root(vector<unordered_set<int>>& v, int parent) {
    auto hs = v[parent];
    for(auto it = hs.begin(); it != hs.end(); it++)
        if(*it != result[parent]) {
            result[*it] = parent;
            root(v, *it); 
        }
}