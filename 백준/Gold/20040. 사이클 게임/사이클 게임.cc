#include <iostream>
using namespace std;

int parent[500001];
int find(int n);
bool merge(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if(merge(a, b)) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}

int find(int n) {
    if (parent[n] == n)
        return n;
    else
        return parent[n] = find(parent[n]);
}

bool merge(int a, int b) {
    int aParent = find(a);
    int bParent = find(b);
    
    if(aParent == bParent)
        return true;
    
    parent[bParent] = aParent;
    return false;
}