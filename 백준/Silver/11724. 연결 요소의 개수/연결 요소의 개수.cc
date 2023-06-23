#include <iostream>
using namespace std;

int root[1001];

int getRoot(int v);

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        root[i] = i;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        int uRoot = getRoot(u);
        int vRoot = getRoot(v);
        if(uRoot != vRoot)
            root[vRoot] = uRoot;
    }

    int result = 0;
    for(int i = 1; i <= n; i++)
        if(root[i] == i)
            result++;
    cout << result << '\n';
    return 0;
}

int getRoot(int v) {
    int result = root[v];
    while(result != root[result])
        result = root[result];
    return result;
}