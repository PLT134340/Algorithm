#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int root[101];

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> v(n + 1);
    for(int i = 1; i <= n; i++) {
        root[i] = i;
        v[i].insert(i);
    }

    for(int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;

        int firstTop = root[first];
        int secondTop = root[second];
        while(root[firstTop] != firstTop)
            firstTop = root[firstTop];
        while(root[secondTop] != secondTop)
            secondTop = root[secondTop];
        if(firstTop != secondTop)
            v[firstTop].merge(v[secondTop]);
        root[secondTop] = firstTop;
    }

    int top = root[1];
    while(root[top] != top)
        top = root[top];
    cout << v[top].size() - 1 << '\n';
    return 0;
}